high=eval(input())
weight=eval(input())
BMI=weight/(high**2)
if(BMI>=28):
    print("肥胖")
elif(BMI<28 and BMI>=24):
    print("超重")
else:
    print("jiu")