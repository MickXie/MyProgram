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