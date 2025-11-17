class Banks():
    def __motto(self): # 定義方法
        return "以客為尊"
    def __init__(self,usename): # 建構子
        self.__usename = usename # 定義屬性
        self.__money =0 # 定義屬性
        self.__bankname = "台灣銀行" # 定義屬性
        self.__rate = 30 # 預設美金與台幣換匯比例
        self.__service_charge = 0.01
        print("目前服務銀行是 ", self.__bankname)
        print("銀行服務理念是 ", self.__motto())

    def get_balance(self): # 獲得存款餘額
        print(self.__usename.title(), " 目前餘額: ", self.__money)
    def save_money(self, money): # 設計存款方法
        self.__money += money # 執行存款
        print("存款 ", money, " 完成")
    def withdraw_money(self, money): # 設計提款方法
        self.__money -= money # 執行提款
        print("提款 ", money, " 完成")
    def __cal_rate(self,usa_d): # 計算換匯這是私有方法
        return int(usa_d * self.__rate * (1 - self.__service_charge))
    def usa_to_taiwan(self, usa_d): # 美金兌換台幣方法
        self.result = self.__cal_rate(usa_d)
        return self.result
    def bank_title(self): # 獲得銀行名稱
        return self.__bankname
class User(Banks):
    pass
class Shilin_Banks(Banks):
# 定義士林分行
    def __init__(self, uname):
        self.bankname = "Taipei Bank - Shilin Branch" # 定義分行名稱
        super().__init__(uname)
userbank = Banks('hung')  # 定義物件userbank
hungbank = Banks('hung') # 定義物件hungbank
hungbank.get_balance() # 獲得存款餘額
hungbank.__balance = 10000 # 外部無法直接存取私有屬性
hungbank.save_money(300) # 存款300元
hungbank.get_balance() # 獲得存款餘額
hungbank.withdraw_money(200) # 提款200元
hungbank.get_balance() # 獲得存款餘額
usdallor = 50
print("我的存款銀行是: ", hungbank.bank_title())
print(usdallor, " 美金可以兌換 ", hungbank.usa_to_taiwan(usdallor), " 台幣")
#class 裡面的函數 ≠ 區域變數 ≠ 普通函數
#類別中定義的所有方法（不管有沒有用到物件屬性）都必須要能被物件呼叫，而 Python 會自動傳入物件本身，所以一定要寫 self。不論方法內是否使用 self，Python 都會自動把物件傳入第一個參數。
#若你想要呼叫「這個物件的」方法 就必須用：self.方法名稱()
hungbank = User('hung') # 定義物件hungbank
hungbank.save_money(500)
hungbank.get_balance()
class Father():
    def __init__(self):
        self.__address = '台北市羅斯福路'
    def getaddr(self):
        return self.__address
class Son(Father):
    pass
hung = Father()
ivan = Son()
print('父類別 : ',hung.getaddr())
print('子類別 : ',ivan.getaddr())

class Person():
    def __init__(self,name):
        self.name = name
class LawerPerson(Person):
    def __init__(self,name):
        self.name = name + "律師"
hung = Person("洪錦魁")
lawer = LawerPerson("洪錦魁")
print(hung.name)
print(lawer.name)
hungbank = Shilin_Banks('Hung') # 定義Shilin_Banks類別物件
print("Hung's banks = ", hungbank.bankname) # 列印銀行名稱

#衍生類別的方法名稱會覆蓋基底類別方法名稱重複的應用

class Father():
    def __init__(self):
        self.fathermoney = 10000   # 父親共有的資產

class Ira(Father):
    def __init__(self):
        self.iramoney = 8000       # Ira 的資產
        super().__init__()         # 父親的資產一起初始化

class Ivan(Father):
    def __init__(self):
        self.ivanmoney = 3000      # Ivan 的資產
        super().__init__()         # 父親的資產一起初始化

    def get_money(self):
        print("Ivan資產:", self.ivanmoney)
        print("父親資產:", self.fathermoney)
        print("Ira資產:", Ira().iramoney)
ivan = Ivan()
ivan.get_money()
print("Ira資產:", Ira().iramoney)

class Animals():
    def __init__(self, animal_name):
        self.name = animal_name
        
    def which(self):
        return 'My pet ' + self.name.title()
        
    def action(self):
        return ' sleeping'
class Dogs(Animals):
    def __init__(self, dog_name):
        super().__init__(dog_name.title())
        
    def action(self):  
        return ' running in the street'
class Monkeys():
    def __init__(self, monkey_name):
        self.name = 'My monkey ' + monkey_name.title()
        
    def which(self):
        return self.name
        
    def action(self):
        return ' running in the forest'
def doing(obj):  
    print(obj.which(), "is", obj.action())
my_cat = Animals('lucy')
doing(my_cat)
my_monkey = Monkeys('taylor')
doing(my_monkey)

class A:
    def __init__(self):
        # super() 會依 MRO（方法解析順序）呼叫下一個父類別的 __init__
        super().__init__()
        
        # 類別 A 設定自己的屬性 x
        # 但後面的類別可能會把 x 覆蓋掉
        self.x = "A"
        print("A init")

class B:
    def __init__(self):
        # super() 會依 MRO 呼叫下一個父類別的 __init__
        super().__init__()
        
        # 類別 B 也會設定屬性 x
        # 若後面的類別也設定 x，則這裡的 x 會被覆蓋
        self.x = "B"
        print("B init")

class C(A, B):   # C 同時繼承 A、B，MRO 為：C → A → B → object
    def __init__(self):
        # 依照 MRO 先呼叫 A.__init__() → 再呼叫 B.__init__()
        super().__init__()
        
        # C 也把 x 設定為 "C"
        # 因為它是最後執行的，所以會覆蓋 A 和 B 的 x
        self.x = "C"
        print("C init")

# 建立 C 類別的物件
obj = C()

# 最後輸出的 x 會是 "C"，因為 C.__init__() 最後執行
print("最後的 x =", obj.x)

class Grandfather():
    pass

class Father(Grandfather):
    pass

class Ivan(Father):
    def fn(self):
        pass

grandfa = Grandfather()
father = Father()
ivan = Ivan()

print("ivan屬於Ivan類別: ", isinstance(ivan, Ivan))          
# True：ivan 物件本身就是 Ivan 類別

print("ivan屬於Father類別: ", isinstance(ivan, Father))      
# True：Ivan 繼承 Father

print("ivan屬於GrandFather類別: ", isinstance(ivan, Grandfather)) 
# True：Ivan → Father → Grandfather

print("father屬於Ivan類別: ", isinstance(father, Ivan))      
# False：Father 不是 Ivan、也不是 Ivan 的子類別

print("father屬於Father類別: ", isinstance(father, Father))  
# True：father 本身就是 Father 類別

print("father屬於Grandfather類別: ", isinstance(father, Grandfather)) 
# True：Father 繼承 Grandfather

print("grandfa屬於Ivan類別: ", isinstance(grandfa, Ivan))    
# False：grandfa 是最上層，不能是子類別

print("grandfa屬於Father類別: ", isinstance(grandfa, Father)) 
# False：同上

print("grandfa屬於Grandfather類別: ", isinstance(grandfa, Grandfather)) 
# True：grandfa 本身就是 Grandfather

def getMax(x, y):
    '''
    文件字串（docstring）示例
    建議 x, y 是整數
    這個函數將傳回較大的值
    '''
    # 將參數轉成整數後比較大小
    if int(x) > int(y):
        return x
    else:
        return y

# 呼叫函數，傳回較大值
print(getMax(2, 3))       # → 3

# 印出 getMax 這個函數的文件字串（也就是上面三引號裡的內容）
print(getMax.__doc__)

"""
============================================================
Python 特殊屬性：__name__  完整教學與範例（整合版）
============================================================

一、什麼是 __name__ ?
------------------------------------------------------------
每一個 Python 模組(module)裡，Python 會自動建立變數 __name__。
它的值分成兩種情況：

(1) 若「直接執行」此檔案：
    __name__ == "__main__"

(2) 若「被其他檔案 import」：
    __name__ == "模組名稱"

因此常看到的寫法：
    
    if __name__ == "__main__":
        main()

意思是：
→ 只有當程式被直接執行時才會跑 main()
→ 被 import 時不會執行 main()（避免副作用）

============================================================
二、範例 1：直接執行與列印 __name__
------------------------------------------------------------
# 這是 ch12_24.py
print("ch12_24.py module name =", __name__)

直接執行此檔案：
輸出： ch12_24.py module name = __main__

被 import 時：
輸出： ch12_24.py module name = ch12_24

============================================================
三、範例 2：__name__ == "__main__" 的用途
------------------------------------------------------------
# 這是 ch12_25.py

def myFun():
    print("__name__ == __main__")

# 若直接執行 ch12_25.py
# (__name__ == "__main__") → True → 執行 myFun()

# 若被 import → 不會執行 myFun()
if __name__ == "__main__":
    myFun()

============================================================
四、範例 3：被 import 時 __name__ 的變化
------------------------------------------------------------

# ch12_24.py（仍然是這段）
print("ch12_24.py module name =", __name__)


# ch12_26.py（匯入 ch12_24）
import ch12_24

執行 ch12_26.py 時：
ch12_24.py module name = ch12_24
(因為 ch12_24.py 被 import，所以 __name__ = 模組名稱)

============================================================
五、重點總結
------------------------------------------------------------
1. 直接執行 py 檔：
     __name__ == "__main__"

2. 被 import：
     __name__ == "模組名稱"

3. 為什麼要寫 if __name__ == "__main__" ?
   → 防止 import 時執行不該跑的程式碼（例如測試碼）

4. 這是 Python 模組化最重要的基本架構。

============================================================
"""
"""
============================================================
Python 特殊方法整理：__str__、__repr__、__iter__、__next__
============================================================

一、__str__(self)
------------------------------------------------------------
用途：
    - 定義當物件被 print() 時，要如何以「人類可讀」的方式顯示。
    - 讓物件變得好讀，不再顯示記憶體位址。

示例（無 __str__ 時）：
    print(a) → <__main__.Name object at 0x...>

示例（有 __str__ 時）：
    print(a) → Hung

使用情境：
    print(obj)
    str(obj)

============================================================
二、__repr__(self)
------------------------------------------------------------
用途：
    - 定義物件在「開發者角度」應該如何被表示。
    - 通常希望這個字串能明確描述物件，甚至可以用來重建物件。
    - repr(obj) 或在互動式模式輸入 obj 會呼叫。

簡化技巧：
    若 __repr__ 與 __str__ 想要相同，只需寫：
        __repr__ = __str__

============================================================
三、__iter__(self)
------------------------------------------------------------
用途：
    - 讓物件變成「可迭代(iterable)」。
    - 必須回傳一個“迭代器(iterator)”物件。
    - 通常迭代器就是 self 自己。

使用情境：
    for x in obj:
    list(obj)
    tuple(obj)

============================================================
四、__next__(self)
------------------------------------------------------------
用途：
    - 定義迭代器在取得「下一個值」時應該做什麼。
    - 必須回傳下一個元素。
    - 當無更多元素時，必須 raise StopIteration。

使用情境：
    next(iterator)
    for 迴圈會自動呼叫 __next__()

============================================================
五、Fibonacci 迭代器完整示範
------------------------------------------------------------
下面的類別 Fib 可以產生不超過 max 的 Fibonacci 數列，
並可被 for 迴圈使用。

class Fib():
    def __init__(self, max):
        # 設定 Fibonacci 的最大值
        self.max = max

    def __iter__(self):
        # 初始化 a, b 為 Fibonacci 前兩項
        self.a = 0
        self.b = 1
        return self  # 本身作為迭代器回傳

    def __next__(self):
        # 每次回傳一個 Fibonacci 值
        fib = self.a

        # 若超過指定最大值，停止迭代
        if fib > self.max:
            raise StopIteration

        # 更新 Fibonacci 兩項
        self.a, self.b = self.b, self.a + self.b

        return fib

使用方式：
    for i in Fib(100):
        print(i)

輸出：
    0 1 1 2 3 5 8 13 21 34 55 89

============================================================
六、總結（最重要概念）
------------------------------------------------------------
__str__()     → print(obj) 時的顯示方式（給人看）
__repr__()    → repr(obj) 時的顯示方式（給程式員看）
__iter__()    → 回傳迭代器，讓物件可被 for 使用
__next__()    → 回傳下一個元素，控制 for 迴圈流程

這些特殊方法統稱為「Magic Methods」（或 dunder methods），
是 Python OOP 高階設計的重要工具。
============================================================
"""
class Counter:
    def __init__(self, max_count):
        self.max = max_count
    def __iter__(self):
        self.n = 1
        return self

    def __next__(self):
        if(self.n>=self.max):
            raise StopIteration
        current = self.n
        self.n += 1
        return current

for num in Counter(5):
    print(num)
# Python 運算子多載（Operator Overloading）
# 讓物件可以使用 ==、!=、>、<、+、-、* 這些符號。
# 透過定義特殊方法（Magic Methods）達成。


# ================================
# 1. 比較運算方法（Comparison Methods）
# ================================
# __eq__  : 等於      self == other
# __ne__  : 不等於    self != other
# __lt__  : 小於      self < other
# __gt__  : 大於      self > other
# __le__  : 小於等於  self <= other
# __ge__  : 大於等於  self >= other

# 決定你的物件「如何比較」。


# ================================
# 2. 數學運算方法（Arithmetic Methods）
# ================================
# __add__      self + other     加法
# __sub__      self - other     減法
# __mul__      self * other     乘法
# __floordiv__ self // other    整數除法
# __truediv__  self / other     除法
# __mod__      self % other     餘數
# __pow__      self ** other    次方

# 用來定義物件間的數值運算行為。


# ================================
# 3. equals() 舊寫法（不用 ==）
# ================================

class City():
    def __init__(self, name):
        self.name = name  # 設定城市名稱

    def equals(self, city2):
        # 用大寫比較 → 忽略大小寫差異
        return self.name.upper() == city2.name.upper()


# 建立三個城市物件
one = City("Taipei")
two = City("taipei")
three = City("myhome")

print(one.equals(two))     # True（台北 == TAIPEI）
print(one.equals(three))   # False（台北 != MYHOME）


# ================================
# 4. 使用 __eq__() 讓 City 支援 ==
# ================================
# 當你寫 one == two 時
# 背後會呼叫：one.__eq__(two)

class City():
    def __init__(self, name):
        self.name = name

    def __eq__(self, city2):
        # 定義 “==” 的判斷方式（忽略大小寫）
        return self.name.upper() == city2.name.upper()


# 建立三個城市物件
one = City("Taipei")
two = City("taipei")
three = City("myhome")

print(one == two)     # True   → 執行 one.__eq__(two)
print(one == three)   # False  → 執行 one.__eq__(three)


# ================================
# 5. 為什麼要用 __eq__ 而不是 equals()？
# ================================
# 因為 __eq__() 讓你的物件可以使用：
#   ==     !=
# 也能與 sorted()、set() 比較時正常運作
# 比 equals() 更符合 Python 的標準用法。


# ================================
# 6. 物件比較方法總整理（最重要表）
# ================================
# __eq__(self, other)   # ==
# __ne__(self, other)   # !=
# __lt__(self, other)   # <
# __gt__(self, other)   # >
# __le__(self, other)   # <=
# __ge__(self, other)   # >=

# __add__(self, other)      # +
# __sub__(self, other)      # -
# __mul__(self, other)      # *
# __truediv__(self, other)  # /
# __floordiv__(self, other) # //
# __mod__(self, other)      # %
# __pow__(self, other)      # **


# ================================
# 使用 __eq__() 的最簡重點：
# ================================
# ✔ 讓物件能用 "==" 比較
# ✔ 比 equals() 更符合 Python 標準
# ✔ 可用在集合、排序、比對資料等地方
