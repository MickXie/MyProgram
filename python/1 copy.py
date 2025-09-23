height_cm = float(input("請輸入身高 (公分): "))
weight = float(input("請輸入體重 (公斤): "))
height_m = height_cm / 100
bmi = weight / (height_m ** 2)
print(f"你的 BMI = {bmi:.2f}")
if bmi < 18.5:
    print("體重過輕")
elif bmi < 24:
    print("正常")
elif bmi < 28:
    print("超重")
else:
    print("肥胖")
