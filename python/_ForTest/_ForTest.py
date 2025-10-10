"""
#!list
print("hellow word")
gg = [11, 22, 33]
print(gg[0])
ff = [[11, 22, 33], [55, 66, 77]]
ff[0][0:1] = [55, 66]
print(ff[0])
#!Tuple
kk = (55, 66, 7)
#!集合
S1={44,33,22}
S2={55,44,33}
S3=S1&S2#交集
S4=S2|S1#聯集
S5=S1-S2#差集
S6=S1^S2#反交集
print (3 in S1)
print (S3)
print (S4)
print (S5)
print (S6)
#!字典
s=set("ff")
y={"ff":"hellow"}
print (y["ff"])
del y["ff"]
print(y)
Y={x:x*2 for x in [3,4,5]}
print (Y)
#!if 
z=input()
z=int(z)
if z>10:
    print (">10")
elif z>2:
    print ("2<10")
else :
    print ("wtff")
c=int(input("hellow \n"))
print (c)
#while
while z>0:
    print ("z有>0")
    z=z-1
    break
else :
    print ("1")
#for in
for x in [1,2,3,4,5]:
    print (x)
    continue
else :
    print ("1")
for x in range(3,4):
    print (x)
#!亂數
import random
data =[0,1,2,3,4,5]
d1=random.choice(data)
d2=random.sample(data,2)
random.shuffle(data)
d3=random.random()
d4=random.uniform(0.0,1.0)
#!常態分配亂數
d5=random.normalvariate(100,10)
#!此100是平均數,10是標準差
#!常態分佈才有_-^-_的分布圖形
print (d1,"\n",d2,"\n",data,"\n",d3,"\n",d4,"\n",d5,"\n", )
import statistics 
E=[1,2,3,4,5,6,7,8,9,10]
#!品均數
e1=statistics.mean(E)
#!中位數(會把極端的資料排除)
e2=statistics.median(E)
#!標準差
e3=statistics.stdev(E)

#!實際對象
class Point :
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def show(self):
        print(self.x,self.y)
p=Point(2,3)
p.show();
class File:
    def __init__(self,name):
        self.name = name
        self.file=None
#!Nonde=0集合
    def open (self):
        self.file=open(self.name ,mode="r",encoding="utf-8")
    def re(self):
        return self.file.read()
f1=File("./texts/txt.txt")
f1.open()
data=f1.re()
print(data)
f2=File("./texts/txt2.txt")
f2.open()
data2=f2.re()
print(data2)

import sys
sys.path.append("D:/Users/Desktop/程式/pytraining")
print(sys.path)
import modules.ggs
modules.ggs.ss()

import json

with open("./texts/txt.txt", mode="r+", encoding="utf-8") as text:
    data = text.read()
    print(data)
    text.write("一一一")
    text.seek(0)  # 将文件指针移动到文件开头
    data = text.read()
    print(data)
    text.write("哈哈哈")
    text.seek(0)  # 将文件指针移动到文件开头
    data = text.read()
    print(data)

with open("./texts/json.json", mode="r+", encoding="utf-8") as json_file:
    data = json.load(json_file)
    print(data)
    print(data["nn"])
    print(data["mm"])
#open("./texts/json.json", mode="r+", encoding="utf-8") as json_file:


import sys
import os
script_path = os.path.abspath(__file__)
absolute_path = os.path.join(os.path.dirname(script_path), )
absolutes_path = os.path.dirname(absolute_path)
print(absolutes_path)
sys.path.append(absolutes_path)
print(sys.path)

import tkinter as tk
import time

def update_time():
    current_time = time.strftime("%H:%M:%S")
    time_label.config(text=current_time)
    # 每秒更新一次時間
    time_label.after(1000, update_time)

# 建立視窗
window = tk.Tk()
window.title("當前時間")
window.geometry("200x50")

# 建立時間標籤
time_label = tk.Label(window, font=("Helvetica", 24))
time_label.pack()

# 開始更新時間
update_time()

# 啟動應用程式的主迴圈
window.mainloop()

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

# ch4_7.py
x = 100
print("x=/%6d/" % x)
y = 10.5
print("y=/%6.2f/" % y)
s = "Deep"
print("s=/%6s/" % s)
print("以下是保留格數空間不足的實例")
print("x=/%2d/" % x)
print("y=/%3.2f/" % y)
print("s=/%2s/" % s)
# ch4_8.py
x = 100
print("x=/%-6d/" % x)
y = 10.5
print("y=/%-6.2f/" % y)
s = "Deep"
print("s=/%-6s/" % s)
# ch4_9.py
x = 10
print("x=/%+6d/" % x)
y = 10.5
print("y=/%+6.2f/" % y)
# ch4_10.py
print(" 姓名 國文 英文 總分")
print("%3s %4d %4d %4d" % ("洪冰儒", 98, 90, 188))
print("%3s %4d %4d %4d" % ("洪雨星", 96, 95, 191))
print("%3s %4d %4d %4d" % ("洪冰雨", 92, 88, 180))
print("%3s %4d %4d %4d" % ("洪星宇", 93, 97, 190))
title = "南極旅遊講座"
print("/{0:*^20s}/".format(title))
a,b=eval(input("Press Enter key to exit."))
max_ = a if a > b else b 
min_ = a if a < b else b
print(f"{max_},{min_}")


"""

# 
#                        _oo0oo_
#                       o8888888o
#                       88" . "88
#                       (| -_- |)
#                       0\  =  /0
#                     ___/`---'\___
#                   .' \\|     |// '.
#                  / \\|||  :  |||// \
#                 / _||||| -:- |||||- \
#                |   | \\\  -  /// |   |
#                | \_|  ''\---/''  |_/ |
#                \  .-\__  '-'  ___/-. /
#              ___'. .'  /--.--\  `. .'___
#           ."" '<  `.___\_<|>_/___.' >' "".
#          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
#          \  \ `_.   \_ __\ /__ _/   .-` /  /
#      =====`-.____`.___ \_____/___.-`___.-'=====
#                        `=---='
# 
# 
#      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 
#                佛祖保佑         永无BUG

