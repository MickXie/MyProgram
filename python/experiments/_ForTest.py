import requests
import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import mplfinance as mpf
import json
from matplotlib import rcParams
import matplotlib.font_manager as fm

# -----------------------------
# Helpers: 資料標準化/安全取值
# -----------------------------
REQUIRED_OHLCV = ["Open", "High", "Low", "Close", "Volume"]

def _flatten_yfinance_columns(df: pd.DataFrame) -> pd.DataFrame:

    if isinstance(df.columns, pd.MultiIndex):
        # 常見情況：第一層是欄位名(Open/High/...)；第二層是 ticker
        # 取 level 0 先保證可以用 df["Open"] 等方式存取
        df = df.copy()
        df.columns = df.columns.get_level_values(0)
    else:
        # 有時欄位會是 tuple 但不是 MultiIndex（極少數）
        if any(isinstance(c, tuple) for c in df.columns):
            df = df.copy()
            df.columns = [c[0] if isinstance(c, tuple) and len(c) > 0 else c for c in df.columns]
    return df

def _ensure_1d_series(x):
    if isinstance(x, pd.DataFrame):
        if x.shape[1] == 1:
            return x.squeeze("columns")
        # 真的遇到多欄（通常是重複欄位或殘留 ticker），取第一欄作為主欄位
        return x.iloc[:, 0]
    return x

def normalize_ohlcv_for_analysis(stock: pd.DataFrame) -> pd.DataFrame:

    stock = _flatten_yfinance_columns(stock)

    missing = [c for c in REQUIRED_OHLCV if c not in stock.columns]
    if missing:
        raise ValueError(f"下載資料缺少欄位：{missing}。目前欄位：{list(stock.columns)}")

    ohlcv = stock.loc[:, REQUIRED_OHLCV].copy()

    # 強制每欄變 1D series，再 to_numeric
    for c in REQUIRED_OHLCV:
        s = _ensure_1d_series(ohlcv[c])
        ohlcv[c] = pd.to_numeric(s, errors="coerce")

    # index 強制 datetime
    ohlcv.index = pd.to_datetime(ohlcv.index, errors="coerce")

    # 移除無效列
    ohlcv.dropna(inplace=True)

    # mplfinance 對 Volume 有時允許 int/float，統一用 float
    ohlcv = ohlcv.astype(float)

    return ohlcv

def safe_scalar(x) -> float:
  
    if isinstance(x, (pd.Series, np.ndarray)):
        return float(pd.Series(x).iloc[-1].item())
    return float(x)

# -------------------------------------------------
# 即時股票資訊（requests + JSON）
# -------------------------------------------------
def get_stock_info(stock_code):
    url = f"https://mis.twse.com.tw/stock/api/getStockInfo.jsp?ex_ch=tse_{stock_code}"
    response = requests.get(url)
    data = response.json()

    if "msgArray" in data and len(data["msgArray"]) > 0:
        info = data["msgArray"][0]

        name = info["n"]
        price = float(info["z"])
        open_price = float(info["o"])
        yesterday = float(info["y"])

        change = price - open_price
        percent_change = (price - yesterday) / yesterday * 100

        print("\n=== 即時股票資訊 ===")
        print(f"股票代號：{stock_code}")
        print(f"股票名稱：{name}")
        print(f"目前價格：{price:.2f}")
        print(f"漲跌價差：{change:.2f}")
        print(f"漲跌幅度：{percent_change:.2f}%")
    else:
        print("無法取得即時股票資訊")


# -------------------------------------------------
# 新增：多隻股票比較功能
# -------------------------------------------------
def compare_multiple_stocks():
    """
    多隻股票比較分析：輸入多個股票代號，比較其報酬率與風險指標
    """
    stock_input = input("請輸入要比較的股票代號，用逗號分隔（例如：2330.TW,2317.TW,2454.TW）：").strip()
    stock_codes = [code.strip() for code in stock_input.split(",")]

    if len(stock_codes) < 2:
        print("請至少輸入兩隻股票進行比較")
        return

    start_date = input("開始日期（YYYY-MM-DD）：")
    end_date = input("結束日期（YYYY-MM-DD）：")

    try:
        start = pd.to_datetime(start_date)
        end = pd.to_datetime(end_date)
    except:
        print("日期格式錯誤")
        return

    # 儲存各股票資料
    stocks_data = {}
    comparison_results = []

    print("\n正在下載股票資料...")

    for code in stock_codes:
        try:
            stock = yf.download(
                tickers=code,
                start=start,
                end=end,
                auto_adjust=False,
                progress=False,
                group_by="column"
            )

            if stock.empty:
                print(f"警告：{code} 查無資料，跳過")
                continue

            ohlcv = normalize_ohlcv_for_analysis(stock)
            stocks_data[code] = ohlcv

            # 計算關鍵指標
            start_price = safe_scalar(ohlcv["Close"].iloc[0])
            end_price = safe_scalar(ohlcv["Close"].iloc[-1])
            total_return = ((end_price - start_price) / start_price) * 100

            high_price = safe_scalar(ohlcv["High"].max())
            low_price = safe_scalar(ohlcv["Low"].min())
            volatility = float(np.std(ohlcv["Close"].pct_change().dropna()) * 100)
            avg_volume = float(np.mean(ohlcv["Volume"].to_numpy()))

            comparison_results.append({
                "code": code,
                "start_price": start_price,
                "end_price": end_price,
                "total_return": total_return,
                "high_price": high_price,
                "low_price": low_price,
                "volatility": volatility,
                "avg_volume": avg_volume
            })

        except Exception as e:
            print(f"警告：{code} 下載或處理失敗 ({e})，跳過")
            continue

    if len(stocks_data) < 2:
        print("成功下載的股票少於兩隻，無法進行比較")
        return

    # 顯示比較結果
    print("\n" + "="*80)
    print("=== 多股票比較分析結果 ===")
    print("="*80)

    df_comparison = pd.DataFrame(comparison_results)
    df_comparison = df_comparison.sort_values("total_return", ascending=False)

    print("\n【報酬率排名】")
    for idx, row in df_comparison.iterrows():
        print(f"{row['code']:12} | 報酬率: {row['total_return']:7.2f}% | "
              f"波動率: {row['volatility']:6.2f}% | "
              f"期間高點: {row['high_price']:8.2f} | 低點: {row['low_price']:8.2f}")

    # 儲存比較結果
    comparison_file = f"comparison_{start_date}_{end_date}.json"
    with open(comparison_file, "w", encoding="utf-8") as f:
        json.dump(comparison_results, f, ensure_ascii=False, indent=2)
    print(f"\n比較結果已儲存至：{comparison_file}")

    # 繪製比較圖表
    # 1. 標準化價格走勢比較（以起始日為 100）
    plt.figure(figsize=(16, 12))

    plt.subplot(3, 1, 1)
    for code, ohlcv in stocks_data.items():
        normalized = (ohlcv["Close"] / ohlcv["Close"].iloc[0]) * 100
        plt.plot(ohlcv.index, normalized, label=code, linewidth=2.5, marker='o',
                markersize=3, markevery=max(1, len(ohlcv)//20))

    plt.title("Normalized Price Comparison (Base = 100)", fontsize=16, fontweight='bold', pad=15)
    plt.ylabel("Normalized Price", fontsize=12)

    plt.legend(loc='best', fontsize=11, framealpha=0.9)
    plt.grid(True, alpha=0.3, linestyle='--')

    # 2. 報酬率比較（水平柱狀圖，更清晰）
    plt.subplot(3, 1, 2)
    colors = ['#2ecc71' if r['total_return'] >= 0 else '#e74c3c' for r in comparison_results]
    codes = [r['code'] for r in comparison_results]
    returns = [r['total_return'] for r in comparison_results]

    # 使用水平柱狀圖，避免 X 軸標籤重疊
    y_pos = np.arange(len(codes))
    bars = plt.barh(y_pos, returns, color=colors, alpha=0.8, edgecolor='black', linewidth=0.5)
    plt.yticks(y_pos, codes, fontsize=11)
    plt.xlabel("Total Return (%)", fontsize=12)
    plt.title("Total Return Comparison", fontsize=16, fontweight='bold', pad=15)

    plt.axvline(x=0, color='black', linestyle='-', linewidth=1)
    plt.grid(True, alpha=0.3, axis='x', linestyle='--')

    # 在柱狀圖旁標註數值
    for i, (bar, ret) in enumerate(zip(bars, returns)):
        width = bar.get_width()
        label_x = width + (max(returns) - min(returns)) * 0.02 if width >= 0 else width - (max(returns) - min(returns)) * 0.02
        plt.text(label_x, i, f'{ret:.2f}%',
                ha='left' if width >= 0 else 'right', va='center',
                fontsize=10, fontweight='bold')

    # 3. 波動率比較（水平柱狀圖）
    plt.subplot(3, 1, 3)
    volatilities = [r['volatility'] for r in comparison_results]
    bars = plt.barh(y_pos, volatilities, color='#f39c12', alpha=0.8, edgecolor='black', linewidth=0.5)
    plt.yticks(y_pos, codes, fontsize=11)
    plt.xlabel("Volatility (%)", fontsize=12)
    plt.title("Volatility Comparison (Std. of Daily Returns)", fontsize=16, fontweight='bold', pad=15)

    plt.grid(True, alpha=0.3, axis='x', linestyle='--')

    # 標註波動率數值
    for i, (bar, vol) in enumerate(zip(bars, volatilities)):
        width = bar.get_width()
        plt.text(width + max(volatilities) * 0.02, i, f'{vol:.2f}%',
                ha='left', va='center', fontsize=10, fontweight='bold')

    plt.tight_layout()
    plt.show()

    # 4. 成交量比較（改用平滑的折線圖 + 移動平均）
    n_stocks = len(stocks_data)
    fig, axes = plt.subplots(1, n_stocks, figsize=(6*n_stocks, 5))

    # 如果只有一隻股票，axes 不是陣列，需要轉換
    if n_stocks == 1:
        axes = [axes]

    for idx, (code, ohlcv) in enumerate(stocks_data.items()):
        ax = axes[idx]

        # 計算 5 日和 20 日移動平均，讓圖表更平滑清晰
        ma5 = ohlcv["Volume"].rolling(window=5, min_periods=1).mean()
        ma20 = ohlcv["Volume"].rolling(window=20, min_periods=1).mean()

        # Draw faded daily volume bars as background
        ax.bar(
            ohlcv.index,
            ohlcv["Volume"],
            alpha=0.2,
            color='#3498db',
            label='Daily Volume'
        )

        # Draw moving average lines for volume
        ax.plot(
            ohlcv.index,
            ma5,
            color='#e74c3c',
            linewidth=2,
            label='Volume MA (5)'
        )
        ax.plot(
            ohlcv.index,
            ma20,
            color='#2ecc71',
            linewidth=2,
            label='Volume MA (20)'
        )


        ax.set_title(f"{code} Volume Analysis", fontsize=13, fontweight='bold')
        ax.set_ylabel("Volume", fontsize=11)
        ax.set_xlabel("Date", fontsize=11)


        ax.legend(loc='best', fontsize=9)
        ax.grid(True, alpha=0.3, linestyle='--')
        ax.ticklabel_format(style='plain', axis='y')

        # 旋轉 X 軸日期標籤
        for label in ax.get_xticklabels():
            label.set_rotation(45)
            label.set_ha('right')

    plt.tight_layout()
    plt.show()


# -------------------------------------------------
# 主分析系統
# -------------------------------------------------
def stock_analysis_system():
    stock_code = input("請輸入台股股票代號（例如 2330.TW）：").strip()

    while True:
        choice = input("是否要查看歷史資料與圖表？(y/n)：").lower()

        if choice == "n":
            get_stock_info(stock_code)
            break

        elif choice == "y":
            start_date = input("開始日期（YYYY-MM-DD）：")
            end_date = input("結束日期（YYYY-MM-DD）：")

            try:
                start = pd.to_datetime(start_date)
                end = pd.to_datetime(end_date)
            except:
                print("日期格式錯誤")
                continue

            # -------------------------------------------------
            # 下載股票資料（明確指定 auto_adjust，避免新版預設改動造成欄位/含義差異）
            # -------------------------------------------------
            try:
                stock = yf.download(
                    tickers=stock_code,
                    start=start,
                    end=end,
                    auto_adjust=False,   # 明確指定，避免預設變動造成混淆
                    progress=False,
                    group_by="column"
                )
                if stock.empty:
                    print("查無資料")
                    continue
            except Exception as e:
                print("下載失敗：", e)
                continue

            # -------------------------------------------------
            # 產生乾淨 OHLCV（後面全部用它）
            # -------------------------------------------------
            try:
                ohlcv = normalize_ohlcv_for_analysis(stock)
            except Exception as e:
                print("資料標準化失敗：", e)
                # debug 提示（只印欄位，避免輸出太長）
                print("原始 columns：", stock.columns)
                continue

            # -------------------------------------------------
            # NumPy 數值分析（改用乾淨 ohlcv，避免 Series/DataFrame 型態不一致）
            # -------------------------------------------------
            high_price = safe_scalar(ohlcv["High"].max())
            low_price = safe_scalar(ohlcv["Low"].min())

            percent_range = (high_price - low_price) / low_price * 100
            avg_close = float(np.mean(ohlcv["Close"].to_numpy()))
            std_volume = float(np.std(ohlcv["Volume"].to_numpy()))

            print("\n=== 數據分析結果 ===")
            print(f"期間最高價：{high_price:.2f}")
            print(f"期間最低價：{low_price:.2f}")
            print(f"區間漲跌幅：{percent_range:.2f}%")
            print(f"平均收盤價（NumPy）：{avg_close:.2f}")
            print(f"成交量標準差（NumPy）：{std_volume:.2f}")

            # -------------------------------------------------
            # RSI（14日，完全避免 Series->float 的 FutureWarning/TypeError）
            # -------------------------------------------------
            close = ohlcv["Close"]
            delta = close.diff()
            gain = delta.clip(lower=0)
            loss = (-delta).clip(lower=0)

            avg_gain = gain.rolling(14, min_periods=14).mean()
            avg_loss = loss.rolling(14, min_periods=14).mean()

            rs = avg_gain / avg_loss.replace(0, np.nan)
            rsi_series = 100 - (100 / (1 + rs))

            # 取最後有效值（避免最後一天剛好 NaN）
            rsi_last = rsi_series.dropna().iloc[-1].item()
            rsi = float(rsi_last)

            print(f"RSI 指標（14 日）：{rsi:.2f}")
            if rsi > 70:
                print("狀態判斷：可能超買")
            elif rsi < 30:
                print("狀態判斷：可能超賣")
            else:
                print("狀態判斷：正常區間")

            # -------------------------------------------------
            # CSV / JSON 儲存（存原始 stock + 摘要）
            # -------------------------------------------------
            csv_name = f"{stock_code}_{start_date}_{end_date}.csv"
            stock.to_csv(csv_name)

            summary = {
                "stock_code": stock_code,
                "start_date": start_date,
                "end_date": end_date,
                "high_price": high_price,
                "low_price": low_price,
                "average_close": avg_close,
                "RSI": rsi
            }

            with open("summary.json", "w", encoding="utf-8") as f:
                json.dump(summary, f, ensure_ascii=False, indent=2)

            print(f"\n資料已儲存為：{csv_name} 與 summary.json")

            # -------------------------------------------------
            # 折線圖 + 成交量（用乾淨 ohlcv）
            # -------------------------------------------------
            # -------------------------------------------------
            # Line chart + Volume (English labels)
            # -------------------------------------------------
            plt.figure(figsize=(12, 6))

            plt.subplot(2, 1, 1)
            plt.plot(ohlcv.index, ohlcv["Close"], linewidth=2)
            plt.title(f"{stock_code} Closing Price Trend")
            plt.ylabel("Price")
            plt.grid(True, alpha=0.3)

            plt.subplot(2, 1, 2)
            plt.bar(ohlcv.index, ohlcv["Volume"], alpha=0.7)
            plt.title("Trading Volume")
            plt.ylabel("Volume")
            plt.xlabel("Date")
            plt.xticks(rotation=45)

            plt.tight_layout()
            plt.show()


            # -------------------------------------------------
            # mplfinance 蠟燭圖（用乾淨 ohlcv：單層欄位、純 float、DatetimeIndex、無 NaN）
            # -------------------------------------------------
            mpf.plot(
              ohlcv,
              type="candle",
              volume=True,
              style="yahoo",
              title=f"{stock_code} Candlestick Chart with Volume",
              figsize=(12, 8)
            )


            break

        else:
            print("請輸入 y 或 n")


# -------------------------------------------------
# 程式進入點（新增主選單）
# -------------------------------------------------
if __name__ == "__main__":
    print("="*50)
    print("   台股分析系統")
    print("="*50)
    print("1. 單一股票分析")
    print("2. 多隻股票比較")
    print("="*50)

    mode = input("請選擇功能（輸入 1 或 2）：").strip()

    if mode == "1":
        stock_analysis_system()
    elif mode == "2":
        compare_multiple_stocks()
    else:
        print("無效的選擇，請重新執行程式")
