animals = ["鼠", "牛", "虎", "兔", "龍", "蛇",
           "馬", "羊", "猴", "雞", "狗", "豬"]
year = int(input("請輸入西元年: "))
index = (year - 4) % 12
print(f"{year} 是 {animals[index]} 年")
