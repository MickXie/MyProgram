import requests
import mplfinance as mpf
import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt
stock_code = ("2317.tw")
symbol = stock_code
start_date = ("2023-5-01")
end_date = ("2023-7-01")
stock = yf.download(symbol, start=start_date, end=end_date)
stock.index = pd.to_datetime(stock.index)
percent_change = round((float(stock['High'].max(
) - float(stock['Low'].min()))) / float(stock['Low'].min()), 4) * 100
print(f"此段時間最高價: {stock['High'].max():.4f}")
print(f"此段時間最低價: {stock['Low'].min():.4f}")
print(f"此段時間漲跌幅度: {percent_change:.4f}%")
print(stock)
print(stock.index)
