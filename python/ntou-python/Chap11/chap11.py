def aaa():
    return 1;   
def interest(interest_type, subject):
    """ 顯示興趣和主題 """
    print("我的興趣是 " + interest_type )
    print("在 " + interest_type + " 中, 最喜歡的是 " + subject)
    print()
interest('旅遊', '敦煌')
interest('程式設計', 'Python')
#特別需留意：函數設計時含有預設值的參數，必需放置在參數列的最右邊
def add(x,y):
    return x + y
print("5 + 10 =", add(5,10))
#if回傳多個值=>回傳tuple
def build_vip(id, name, tel = ''):
    """ 建立VIP資訊 """
    vip_dict = {'VIP_ID':id, 'Name':name}
    if tel:
        vip_dict['Tel'] = tel
    return vip_dict
member1 = build_vip('101', 'Nelson')
member2 = build_vip('102', 'Henry', '0952222333')
while True:
    print("建立VIP資訊系統")
    idnum = input("請輸入ID: ")
    name = input("請輸入姓名: ")
    tel = input("請輸入電話號碼: ") # 如果直接按Enter可
    member = build_vip(idnum, name, tel) # 建立字典
    print(member, '\n')
    repeat = input("是否繼續(y/n)? 輸入非y字元可結束系統: ")
    if repeat != 'y':
        break
    print("歡迎下次再使用")
    
def product_msg(customers):
    str1 = '親愛的: '
    str2 = '本公司將在2020年12月20日北京舉行產品發表會'
    str3 = '總經理:深石敬上'
    for customer in customers:
        msg = str1 + customer + '\n' + str2 + '\n' + str3
        print(msg, '\n')
members = ['Damon', 'Peter', 'Mary']
product_msg(members)
#函數傳遞串列時有一點必需留意，假設參數串列的預設值是空串列，在重複呼叫過程預設串列會遺留先前呼叫的內容
def insertChar(letter, myList=[], inList=[1,2]):
    myList.append(letter)
    inList.append(letter)
    print(myList)
    print(inList)
insertChar('x')
insertChar('y')
#['x']
#[1, 2, 'x']
#['x', 'y']
#[1, 2, 'x', 'y']
def  calculate_average(*numbers):
    return sum(numbers)/len(numbers)
ans=calculate_average(10,102,3032,12301,231,231,2,)
print("平均值 =", ans)
def find_max_min(numbers):
    return max(numbers), min(numbers)
print(find_max_min([5, 10, 3, 8, 2]))
# ------------------------------------------------------------
# Python 中的 * 與 ** 有兩種不同用途：
#   1. 用在函式定義中（def 參數區） → 打包（packing）
#   2. 用在函式呼叫或一般語法中 → 展開（unpacking）
# ------------------------------------------------------------

# ------------------------------------------------------------
# ① 在函式定義中：
#    *args    → 接收任意數量的位置參數，打包成 tuple
#    **kwargs → 接收任意數量的 key=value 參數，打包成 dict
#    ★ 注意：這種「打包語法」只能用在 def 函式定義裡。
# ------------------------------------------------------------

def demo_function(*args, **kwargs):
    print(args)     # 位置參數被打包成 tuple
    print(kwargs)   # 關鍵字參數被打包成 dict

# ------------------------------------------------------------
# ② 在函式呼叫或一般語法中：
#    *iterable  → 展開序列，如 list, tuple
#    **dict     → 展開字典的 key=value
#    ★ 展開（unpacking）可以在任何地方使用，不限於函式內或外。
# ------------------------------------------------------------

# 展開 list（unpacking）
nums = [1, 2, 3]
print(*nums)   # 等同 print(1, 2, 3)

# 合併 list（展開放入新 list）
a = [1, 2]
b = [*a, 3, 4]   # [1, 2, 3, 4]

# 展開 dict（函式呼叫時）
data = {"x": 10, "y": 20}

def test(x, y):
    print(x, y)

test(**data)   # 等同 test(x=10, y=20)

# ------------------------------------------------------------
# 結論：
#   *args / **kwargs → 只能在「函式定義」中用於參數「打包」。
#   * / **（展開） → 可以在程式的任何地方使用，用於「拆開」序列或字典。
# ------------------------------------------------------------

# 定義一個自訂函數 total，用來計算資料總和
def total(data):
    return sum(data)  # 直接使用 Python 的 sum() 計算總和

# 建立一個 tuple（不可變序列）
x = (1, 5, 10)

# 建立一個串列，裡面放「函數物件」而不是數字或字串
# 這四個函數會被依序取出執行
myList = [min, max, sum, total]

# 用 for 迴圈逐一取出函數 f，並以 f(x) 呼叫它們
for f in myList:
    # f 代表目前取出的函數，例如第一次是 min、第二次是 max ...
    # print(f) 會顯示函數的記憶體位置或名稱
    # print(f(x)) 則會執行該函數並印出結果
    print(f, f(x))

# 定義一個加法函數 add
def add(x, y):
    return x + y

# 定義一個乘法函數 mul
def mul(x, y):
    return x * y

# running() 函數可以接收另一個函數作為參數
# func : 要執行的函數（例如 add 或 mul）
# arg1, arg2 : 要傳入 func 的兩個參數
def running(func, arg1, arg2):
    return func(arg1, arg2)   # 呼叫傳入的函數 func

# 把 add 函數當作「資料」傳入 running
result1 = running(add, 5, 10)   # 等同於 add(5, 10)
print(result1)  # 印出 15

# 把 mul 函數傳入 running
result2 = running(mul, 5, 10)   # 等同於 mul(5, 10)
print(result2)  # 印出 50

# ch11_25_5.py
def dist(x1,y1,x2,y2): # 計算2點之距離函數
    def mySqrt(z): # 計算開根號值
        return z ** 0.5
    dx = (x1 - x2) ** 2
    dy = (y1 - y2) ** 2
    return mySqrt(dx+dy)
print(dist(0,0,1,1))

# ch11_25_6.py
def outer():
    def inner(n):
        print('inner running')
        return sum(range(n))
    return inner
f = outer() # outer()傳回inner位址
print(f) # 列印inner記憶體
print(f(5)) # 實際執行的是inner()
y = outer()
print(y)
print(y(10))
def factorial1(n):
    """ 計算n的階乘, n 必須是正整數 """
    if n == 1:
        return 1
    else:
        return (n * factorial(n-1))
def factorial_stack(n):
    stack = []              # 建立堆疊
    result = 1              # 最終結果

    # 將 1 到 n push 進堆疊
    for i in range(1, n + 1):
        stack.append(i)     # push 動作

    # 不斷 pop 出來相乘
    while stack:
        top = stack.pop()   # pop 出堆疊最上面一個
        result *= top       # 累乘

    return result

#在函數內不能更改全域變數的值 如果要在函數內要存取或修改全域變數值，需在函數內使用global宣告此變數
#locals( )：可以用字典方式列出所有的區域變數名稱與內容
#globals( )：可以用字典方式列出所有的全域變數名稱與內容
# 這個函式用來示範 nonlocal 與 global 的運作方式
def local_fun():

    # 這是 local_fun() 的「區域變數」
    # 不是全域變數 var_nonlocal
    var_nonlocal = 22    

    # 定義內層函式（巢狀函式）
    def local_inner():
        # 宣告要使用並修改全域變數 var_global
        global var_global

        # 宣告使用外層函數 local_fun 的變數 var_nonlocal
        nonlocal var_nonlocal

        # 修改全域變數 var_global（global 指定）
        var_global = 111

        # 修改外層函數 local_fun 的 var_nonlocal（nonlocal 指定）
        var_nonlocal = 222

    # 呼叫內層函式，執行變數修改
    local_inner()

    # 印出目前的全域變數（經過 local_inner() 之後變 111）
    print('local_fun輸出 var_global = ', var_global)

    # 印出外層函式的 var_nonlocal（經 nonlocal 修改後變 222）
    print('local_fun輸出 var_nonlocal = ', var_nonlocal)


# ------------------------------------------------------------

# 以下是全域變數（在整個程式可使用）
var_global = 1        # 全域變數 var_global
var_nonlocal = 2      # 全域變數 var_nonlocal（與函式中的不同）

# 呼叫 local_fun() 前，先印出全域變數內容
print('主程式輸出 var_global = ', var_global)     # 1
print('主程式輸出 var_nonlocal = ', var_nonlocal) # 2

# 呼叫函式，會修改 var_global（global）
# 但不會修改全域 var_nonlocal
local_fun()

# 再次印出全域變數
print('主程式輸出 var_global = ', var_global)     # 被改成 111
print('主程式輸出 var_nonlocal = ', var_nonlocal) # 仍然是 2

square = lambda x: x ** 2
# ------------------------------------------------------------
# Python 匿名函數 lambda 完整筆記（中文）
# ------------------------------------------------------------
# lambda 是 Python 的匿名函數（沒有名字）
# 適用於：
#   ✔ 一行的小函數
#   ✔ 不需要另外定義 def
#   ✔ map、filter、sorted 等地方
#
# 基本語法：
#   lambda 參數1, 參數2, ... : 表達式
#
# 特點：
#   ✔ 只能寫一行
#   ✔ 不需要寫 return（會自動回傳）
#   ✔ 可以有多個參數
# ------------------------------------------------------------


# ------------------------------------------------------------
# 1. 一般函數 vs lambda（平方運算）
# ------------------------------------------------------------

# 一般函數版本
def square(x):
    value = x ** 2        # 計算平方
    return value          # 回傳結果

print(square(10))         # 輸出 100


# 同樣功能的 lambda 寫法
# square 是變數，用來存匿名函數
square = lambda x: x ** 2

print(square(10))         # 輸出 100


# ------------------------------------------------------------
# 2. 多參數 lambda（乘法）
# ------------------------------------------------------------

# 建立匿名函數，接收 x, y 兩個參數
product = lambda x, y: x * y

print(product(5, 10))     # 輸出 50


# ------------------------------------------------------------
# 3. lambda 與 def 的差異（重要整理）
# ------------------------------------------------------------
# lambda：
#   - 匿名函數（沒有名字）
#   - 只能寫一行
#   - 不需要 return
#   - 適合簡短計算
#
# def：
#   - 有名字
#   - 可以寫多行
#   - 需要 return
#   - 適合複雜邏輯
# ------------------------------------------------------------


# ------------------------------------------------------------
# 4. lambda 適合使用的場景：
#   ✔ 排序 sorted()
#   ✔ 過濾 filter()
#   ✔ 映射 map()
#   ✔ 一次性的小函數
#   ✔ 傳入其他函數當作參數
# ------------------------------------------------------------


# ------------------------------------------------------------
# 總結：
#   lambda = 一行的小函數，只用於簡短運算，不用寫 return。
# ------------------------------------------------------------
def oddfn(x):
    return x if (x % 2 == 1) else None

mylist = [5, 10, 15, 20, 25, 30]

# filter(函數, 可迭代序列) → 回傳 filter object
filter_object = filter(oddfn, mylist)
print(filter_object)
oddlist = list(filter(lambda x: (x % 2 == 1), mylist))
print("奇數串列: ", oddlist)  # [5, 15, 25]
# 用串列生成式取出所有保留下來的項目
print("奇數串列: ", [item for item in filter_object])  # [5, 15, 25]
squarelist = list(map(lambda x: x ** 2, mylist))
print("串列的平方值: ", squarelist)
#全部轉換成字串:list(map(str, mylist))
print("串列的字串值: ", list(map(str, mylist)))