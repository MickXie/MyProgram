year=5
rate=0.015
money=5
Total = money * ( 1 + rate)**year
print(Total)
#用round()可以限制小數點 round(數值, 小數位數) 會四捨五入到指定的小數位數。
print(round(Total, 2))
#用 f-string 格式化輸出（推薦） .2f 代表「保留 2 位小數，四捨五入」。
print(f"5年後的本金和為：{Total:.2f}")
#用 format() 函數 和 f-string 效果一樣
print("5年後的本金和為：{:.2f}".format(Total))



