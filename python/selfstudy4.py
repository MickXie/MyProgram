import requests
import mplfinance as mpf
import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt
# 股票資訊獲取


def get_stock_info(stock_code):
    url = f"https://mis.twse.com.tw/stock/api/getStockInfo.jsp?ex_ch=tse_{stock_code}"
    response = requests.get(url)
    data = response.json()

    if 'msgArray' in data and len(data['msgArray']) > 0:
        stock_info = data['msgArray'][0]
        name = stock_info['n']
        price = round(float(stock_info['z']), 2)
        change = round(float(stock_info['h']) - float(stock_info['l']), 2)
        percent_change = round(
            (float(stock_info['z']) - float(stock_info['y'])) / float(stock_info['y']), 4) * 100
        print(f"股票代號: {stock_code}")
        print(f"股票名稱: {name}")
        print(f"今日/當下股價: {price:.4f}")
        print(f"今日漲跌價差: {change:.4f}")
        print(f"今日漲跌幅度: {percent_change:.4f}%")

    else:
        print("找不到股票資訊或 API 回應中的 '股票相關資訊' 列表為空。")
# 意問答程式


def asking_system(cwilling, stock_code):
    if cwilling == "y":
        start_date = input("請問要從什麼時間開始看(ex: 2023-3-01)：")
        end_date = input("請問要到什麼結束(ex: 2023-3-01)：")
        symbol = stock_code
        has_error = False
        get_stock_info(stock_code)
        print(f"你所選擇的時間區段是: {start_date}--{end_date},")
        try:
            stock = yf.download(symbol, start=start_date, end=end_date)
            stock.index = pd.to_datetime(stock.index)
            percent_change = round((float(stock['High'].max(
            ) - float(stock['Low'].min()))) / float(stock['Low'].min()), 4) * 100
            print(f"此段時間最高價: {stock['High'].max():.4f}")
            print(f"此段時間最低價: {stock['Low'].min():.4f}")
            print(f"此段時間漲跌幅度: {percent_change:.4f}%")
            mpf.plot(stock, type='candle',
                     title=f"{symbol} Candlestick Chart", ylabel='Price', ylabel_lower='Volume')
            plt.show()
        except Exception as e:
            print("無法獲取股票數據，請檢查輸入的日期和股票代碼是否正確", "下載股票數據時出錯：", e)
            has_error = True
        if has_error:
            return
    elif cwilling == "n":
        print("ok")
        get_stock_info(stock_code)
    else:
        print("answer: y or n")
        cwilling = input("是否要看該股票的相關資訊(ex: y/n)：")
        asking_system(cwilling, stock_code)


# 執行主程序
stock_code = input("請輸入台股股票代號(ex: 台積電：2330.tw)：")
cwilling = input("是否要看該股票的相關資訊(ex: y/n)：")
asking_system(cwilling, stock_code)
