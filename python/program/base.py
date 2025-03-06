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
"""
