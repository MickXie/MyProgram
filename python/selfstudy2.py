import requests
import mplfinance as mpf
import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt


def get_stock_info(stock_code):
    url = f"https://mis.twse.com.tw/stock/api/getStockInfo.jsp?ex_ch=tse_{stock_code}"
    response = requests.get(url)
    data = response.json()

    if 'msgArray' in data and len(data['msgArray']) > 0:
        stock_info = data['msgArray'][0]
        name = stock_info['n']
        price = float(stock_info['z'])
        change = float(stock_info['w'])
        percent_change = float(stock_info['y'])

        print(f"股票代號: {stock_code}")
        print(f"股票名稱: {name}")
        print(f"股價: {price:.4f}")
        print(f"漲跌價差: {change:.4f}")
        print(f"漲跌幅度: {percent_change:.4f}%")
    else:
        print("找不到股票資訊或 API 回應中的 'msgArray' 列表為空。")


def asking_system(cwilling, stock_code):
    if cwilling == "y":
        start_date = input("請問要從什麼時間開始看該股票的 Candlestick(ex:2023-3-01)：")
        end_date = input("請問要到什麼結束(ex:2023-3-01)：")
        symbol = stock_code
        has_error = False

        try:
            stock = yf.download(symbol, start=start_date, end=end_date)
            stock.index = pd.to_datetime(stock.index)
            get_stock_info(stock_code)
            mpf.plot(stock, type='candle',
                     title=f"{symbol} Candlestick Chart", ylabel='Price', ylabel_lower='Volume')
            plt.show()
        except Exception as e:
            print("下載股票數據時出錯：", "無法獲取股票數據，請檢查輸入的日期和股票代碼是否正確")
            has_error = True
        if has_error:
            return
    elif cwilling == "n":
        print("ok")
        get_stock_info(stock_code)
    else:
        print("answer: y or n")
        cwilling = input("是否要看相關的 Candlestick 圖(ex: y/n)：")
        asking_system(cwilling, stock_code)


# 執行爬取股票資訊
stock_code = input("請輸入台股股票代號：")
cwilling = input("是否要看相關的 Candlestick 圖(ex: y/n)：")
asking_system(cwilling, stock_code)
