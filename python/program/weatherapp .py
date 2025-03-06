import requests
import tkinter as tk
from tkinter import messagebox

# OpenWeatherMap API密钥
API_KEY = "YOUR_API_KEY"

# 创建GUI窗口
window = tk.Tk()
window.title("天气应用程序")

# 处理选择的地区
def get_weather():
    city = city_entry.get()
    if city:
        try:
            # 发送API请求
            url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}"
            response = requests.get(url)
            data = response.json()

            # 解析API响应
            if data["cod"] == 200:
                weather = data["weather"][0]["description"]
                temperature = data["main"]["temp"]
                temperature = round(temperature - 273.15, 2)  # 将温度从开尔文转换为摄氏度
                messagebox.showinfo("天气", f"{city}的天气：{weather}\n温度：{temperature}℃")
            else:
                messagebox.showerror("错误", "无法获取天气信息。")
        except requests.exceptions.RequestException:
            messagebox.showerror("错误", "网络连接失败。")
    else:
        messagebox.showwarning("警告", "请选择地区。")

# 创建GUI组件
city_label = tk.Label(window, text="地区：")
city_label.pack()

city_entry = tk.Entry(window)
city_entry.pack()

get_weather_button = tk.Button(window, text="获取天气", command=get_weather)
get_weather_button.pack()

# 运行GUI主循环
window.mainloop()
