James = ['Lebron James',23, 19, 22, 31, 18] # 定義James串列
print("列印James串列", James)
print("串列james資料型態是: ",type(James))#Python 的每種資料型態（像 list、tuple、dict）都有自己的顯示格式（representation）。print() 會自動把 list 轉成可讀格式，所以不需要迴圈。
# Python 支援「序列拆包（unpacking）」功能
# 只要右邊是可迭代物件（list / tuple / string / dict 的 key ...），
# 就可以一次把多個元素分配給多個變數。
James = ['Lebron James', 23, 19, 22, 31, 18]  # 一個含 6 個元素的串列
# 序列拆包：左邊有 6 個變數，右邊剛好也有 6 個元素，因此可以成功
name, game1, game2, game3, game4, game5 = James
# 拆包結果：
# name  = 'Lebron James'
# game1 = 23
# game2 = 19
# game3 = 22
# game4 = 31
# game5 = 18
# ⚠ 注意：
# 拆包時「左右數量必須相同」，否則會 ValueError。
# 例如：
# a, b = James  # ❌ 錯誤：左邊變數只有 2 個，但右邊有 6 個元素
# ✔ 若想讓其中一個變數接收多餘的值，可以使用星號（*）
name2, *scores = James
# name2 = 'Lebron James'
# scores = [23, 19, 22, 31, 18]
# === 串列切片（list slicing）教學 ===
# 假設串列如下：
mylist = ['A', 'B', 'C', 'D', 'E', 'F']
# 索引:     0    1    2    3    4    5
# 負索引:   -6   -5   -4   -3   -2   -1
# 1. mylist[start:end]
#    取得從索引 start 到 end-1（不包含 end）
print(mylist[1:4])    # ['B', 'C', 'D']
# 2. mylist[:end]
#    從開頭取到 end-1
print(mylist[:3])     # ['A', 'B', 'C']
# 3. mylist[:-n]
#    取得前面所有元素，但「不包含最後 n 個」
print(mylist[:-2])    # ['A', 'B', 'C', 'D']
# 4. mylist[start:]
#    從索引 start 一直取到最後
print(mylist[2:])     # ['C', 'D', 'E', 'F']
# 5. mylist[-n:]
#    取得串列「最後 n 個」元素
print(mylist[-3:])    # ['D', 'E', 'F']
# 6. mylist[:]
#    取得全部元素（相當於複製整個串列）
print(mylist[:])      # ['A', 'B', 'C', 'D', 'E', 'F']
# 7. mylist[start:end:step]
#    從 start 到 end-1，每隔 step 取一個
print(mylist[0:6:2])  # ['A', 'C', 'E']
# 額外：反轉串列（步進為 -1）
print(mylist[::-1])   # ['F', 'E', 'D', 'C', 'B', 'A']

james = [23, 19, 22, 31, 18] # 定義james串列
print("列印james第1-3場得分",james[:3])
print("列印james第2-4場得分", james[1:4])
print("列印james第1,3,5場得分", james[0:5:2])
print("列印james第4場得分", james[-2])

# max(), min(), sum() 都是 Python 內建函數（built-in functions）
# 可用來處理串列、元組等「可迭代物件」中的數字

james = [23, 19, 22, 31, 18]  # 定義 james 這 5 場比賽的得分列表

# max()：回傳串列中的最大值
print("最高得分 = ", max(james))   # 31

# min()：回傳串列中的最小值
print("最低得分 = ", min(james))   # 18

# sum()：將串列裡所有元素加總
print("得分總計 = ", sum(james))   # 113


James = ['Lebron James', 23, 19, 22, 31, 18] # 定義james的5場比賽得分
print("最高得分 = ", max(James[1:]))
print("最低得分 = ", min(James[1:]))
print("得分總計 = ", sum(James[1:]))

games = len(James[1:])#len() : 計算串列個數
print(games)
#Python 允許 “+” 與 “+=” 執行串列相加
cars1 = ['Toyota', 'Nissan', 'Honda']
print("舊汽車銷售品牌", cars1)
cars2 = ['Audi', 'BMW']
cars1 += cars2
print("新汽車銷售品牌", cars1)
cars = ['toyota', 'nissan', 'honda']
nums = [1, 3, 5]
carslist = cars * 3 # 串列乘以數字
print(carslist)
numslist = nums * 5 # 串列乘以數字
print(numslist)

James = ['Lebron James',23, 19, 22, 31, 18] # 定義James串列
Love = ['Kevin Love',20, 18, 30, 22, 15] # 定義Love串列
game3 = James[4] + Love[4]
LKgame = James[0] + ' 和 ' + Love[0] + '第四場總得分 = '
print(LKgame, game3)

# === 串列刪除（del）教學 ===
# del 是 Python 的刪除語句，用來刪除串列中的元素。
# 刪除時可搭配索引或切片來控制刪除範圍。


# 1. del mylist[i]
#    刪除索引 i 的單一元素
nums1 = [1, 3, 5]
print("刪除 nums1 串列索引 1 元素前 =", nums1)
del nums1[1]          # 刪掉索引 1 的元素（3）
print("刪除 nums1 串列索引 1 元素後 =", nums1)  # [1, 5]


# 2. del mylist[start:end]
#    刪除從 start 到 end-1 的所有元素（切片刪除）
nums2 = [1, 2, 3, 4, 5, 6]
print("刪除 nums2 串列索引 [0:2] 前 =", nums2)
del nums2[0:2]        # 刪掉索引 0 和 1（1, 2）
print("刪除 nums2 串列索引 [0:2] 後 =", nums2)  # [3, 4, 5, 6]


# 3. del mylist[start:end:step]
#    使用步進 step，每隔 step 刪除一個元素
nums3 = [1, 2, 3, 4, 5, 6]
print("刪除 nums3 串列索引 [0:6:2] 前 =", nums3)
del nums3[0:6:2]      # 刪掉索引 0, 2, 4 → 1, 3, 5
print("刪除 nums3 串列索引 [0:6:2] 後 =", nums3)  # [2, 4, 6]


# 4. 範例：刪除勇士隊陣容中的某位球員
warriors = ['Curry', 'Durant', 'Iquodala', 'Bell', 'Thompson']
print("2018 年初 NBA 勇士隊主將陣容 =", warriors)
del warriors[3]        # 刪掉索引 3（'Bell'）
print("2018 年末 NBA 勇士隊主將陣容 =", warriors)

#字串的物件導向
# ---------------------------------------
# 1. lower()
# 將字串所有英文字母轉成小寫
# 例："Hello".lower() → "hello"
# ---------------------------------------

# 2. upper()
# 將字串所有英文字母轉成大寫
# 例："Hello".upper() → "HELLO"
# ---------------------------------------

# 3. title()
# 將字串每個單字的第一個字母大寫，其餘小寫
# 例："hello world".title() → "Hello World"
# ---------------------------------------

# 4. swapcase()
# 大寫變小寫，小寫變大寫
# 例："Hello".swapcase() → "hELLO"
# ---------------------------------------

# 5. rstrip()
# 刪除字串「尾端」多餘空白（right strip）
# 例："hello   ".rstrip() → "hello"
# ---------------------------------------

# 6. lstrip()
# 刪除字串「開頭」多餘空白（left strip）
# 例："   hello".lstrip() → "hello"
# ---------------------------------------

# 7. strip()
# 刪除字串「前後」兩側的多餘空白（left + right）
# 例："   hello   ".strip() → "hello"
# ---------------------------------------

# 8. center(width)
# 使字串在指定寬度中置中對齊
# 例："hi".center(10) → "    hi    "
# ---------------------------------------

# 9. rjust(width)
# 字串在指定寬度中靠右對齊（right justify）
# 例："hi".rjust(10) → "        hi"
# ---------------------------------------

# 10. ljust(width)
# 字串在指定寬度中靠左對齊（left justify）
# 例："hi".ljust(10) → "hi        "
# ---------------------------------------

# 11. zfill(width)
# 字串靠右，不足的地方用 0 填補（常用於數字格式）
# 例："123".zfill(5) → "00123"
# ---------------------------------------

# append()：在串列最後新增一個元素,可加串列
numbers = [1, 2, 3]
numbers.append(4)  # 把 4 加到最後
print(numbers)     # [1, 2, 3, 4]

# ----------------------------------------------------

# insert()：在指定索引位置插入新元素，其後元素會往右移
numbers2 = [10, 20, 30]
numbers2.insert(1, 99)  # 在索引 1 插入 99
print(numbers2)          # [10, 99, 20, 30]

# ----------------------------------------------------
# append() 永遠加在最後
# insert(i, x) 可以在任意位置插入 x

# === pop()：用索引刪除，並回傳被刪除的值 ===
nums1 = [10, 20, 30, 40]

value1 = nums1.pop(1)  # 刪除索引 1 的元素（20）
print(nums1)           # [10, 30, 40]
print(value1)          # 20（pop() 會回傳刪除的元素）

value2 = nums1.pop()   # 不給索引 → 刪除最後一個（40）
print(nums1)           # [10, 30]
print(value2)          # 40


# -----------------------------------------------------

# === remove()：用「元素值」刪除，不回傳 ===
nums2 = [1, 2, 3, 2, 4]

nums2.remove(2)        # 尋找並刪掉第一個值為 2 的元素
print(nums2)           # [1, 3, 2, 4]（只刪第一個 2）

# remove() 不會回傳被刪除的值，回傳值是 None


# -----------------------------------------------------
# pop() vs remove() 總結：
# pop(index)  → 用索引刪，會回傳刪掉的元素
# pop()       → 刪除最後一個
# remove(x)   → 用元素值刪除第一個 x，不回傳值

# reverse()：反轉串列順序（不排序）
numbers = [1, 2, 3, 4]
numbers.reverse()   # 直接改原串列
print(numbers)      # [4, 3, 2, 1]

# ----------------------------------------------------

# sort()：排序（由小到大），直接修改原串列
nums1 = [5, 3, 1, 4, 2]
nums1.sort()        # 升冪排序
print(nums1)        # [1, 2, 3, 4, 5]

nums1.sort(reverse=True)  # 降冪排序
print(nums1)              # [5, 4, 3, 2, 1]

# ----------------------------------------------------

# sorted()：排序但不改原串列，會回傳新的串列
nums2 = [5, 3, 1, 4, 2]
new_nums = sorted(nums2)           # 升冪排序
new_nums_desc = sorted(nums2, reverse=True)  # 降冪排序

print(new_nums)        # [1, 2, 3, 4, 5]
print(new_nums_desc)   # [5, 4, 3, 2, 1]
print(nums2)           # 原本的 nums2 不變


cars = ['honda','bmw','toyota','ford']#字母大小比較
print("目前串列car內容 = ",cars)
print("使用sorted( )由小排到大")
cars_sorted = sorted(cars,reverse=True)
print("排序串列結果 = ",cars_sorted)
print("原先串列car內容 = ",cars)
nums = [5, 3, 9, 2]
print("目前串列num內容 = ",nums)
print("使用sorted( )由小排到大")
nums_sorted = sorted(nums,reverse=True)
print("排序串列結果 = ",nums_sorted)
print("原先串列num內容 = ",nums)

# index(搜尋值)：回傳搜尋值在串列中的第一個索引位置
# 如果搜尋值不存在，會產生 ValueError

cars = ['honda', 'bmw', 'toyota', 'ford']

# 找到 'toyota' 的索引位置
pos = cars.index('toyota')
print(pos)  # 2  （toyota 位於索引 2）


James = ['Lebron James',23, 19, 22, 31, 18] # 定義James串列
Max=max(James[1:])
game=James.index(Max)
print(f"他在第{game:2d}場得最高分,得了{Max:2d}分")

# count(搜尋值)：計算搜尋值在串列中出現的次數
# 若搜尋值不存在，回傳 0，不會報錯

nums = [1, 2, 3, 2, 4, 2]

count_2 = nums.count(2)  # 計算 2 出現幾次
print(count_2)           # 3

count_9 = nums.count(9)  # 9 不存在
print(count_9)           # 0

James = [['Lebron James','SF','12/30/84'],23,19,22,31,18] # 定義James串列
games = len(James) # 求元素數量
score_Max = max(James[1:games]) # 最高得分
i = James.index(score_Max) # 場次
name = James[0][0]
position = James[0][1]
born = James[0][2]
print("姓名 : ", name)
print("位置 : ", position)
print("出生日期 : ", born)
print(f"在第 {i} 場得最高分 {score_Max}")

# append(串列B)：將串列B當成「一個元素」加入串列A
a = [1, 2, 3]
b = [4, 5]
a.append(b)
# 結果：[1, 2, 3, [4, 5]]
# b 被整包加入，成為 a 的一個新元素

# ----------------------------------------------

# extend(串列B)：將串列B「展開」後逐一加入串列A
a = [1, 2, 3]
b = [4, 5]
a.extend(b)
# 結果：[1, 2, 3, 4, 5]
# b 的每個值都被加到 a 裡，不會變成巢狀列表

#切片拷貝(copy)觀念是，執行拷貝後產生新串列物件，當一個串列改變後，不會影響另一個串列的內容
#從friendsports = mysports多一個friendsports = mysports[:]即可

# 賦值：b = a
# a 和 b 指向同一個串列物件，兩者完全連動

a = [1, 2, 3]
b = a
b[0] = 99
# a 和 b 會同時變成 [99, 2, 3]

# ---------------------------------------------------

# 淺拷貝：b = a.copy()
# a 和 b 外層是獨立的物件，但如果裡面有子物件（例如列表）
# 內層子物件依然指向同一份資料

a = [1, 2, [10, 20]]
b = a.copy()

b[0] = 99        # 不會影響 a（因為外層是獨立的）
b[2][0] = 777    # 會影響 a（因為內層是共享的）

# 結果：
# a = [1, 2, [777, 20]]
# b = [99, 2, [777, 20]]

# 深拷貝 deepcopy：將 a 的所有資料（外層＋內層）完整複製一份
# a 和 b 完全獨立，不會互相影響
# 使用前要 import copy 模組

import copy

a = [1, 2, [10, 20]]

# 執行深拷貝
b = copy.deepcopy(a)

b[0] = 99        # 修改 b 的外層，不會影響 a
b[2][0] = 777    # 修改 b 的內層，也不會影響 a（因為深拷貝內層也複製了）

print(a)   # [1, 2, [10, 20]]
print(b)   # [99, 2, [777, 20]]

#f"{變數 = }"會顯示變數 = 值
x = 5
print(f"{x = }")#x = 5

# split()：分割字串，回傳串列（list）

str1 = "Silicon Stone Education"
str2 = "D:\\Python\\ch6"   # 字串中的 "\" 需要用 "\\" 來表示

# 1. split() 沒有參數時 → 以空格拆成串列
sList1 = str1.split()
# 結果 ['Silicon', 'Stone', 'Education']

# 2. split(ch) → 以指定字元 ch 拆成串列
# 因為 "\" 是逸出字元，需要寫成 "\\"
sList2 = str2.split("\\")

print(str1, " 串列內容是 ", sList1)
print(str1, " 串列字數是 ", len(sList1))

print(str2, " 串列內容是 ", sList2)
print(str2, " 串列字數是 ", len(sList2))

# join()：將串列中的字串用「指定分隔字串」連接起來，變成一個完整字串連接字串.join(串列)


path = ['D:', 'ch6', 'ch6_49.py']

connect = '\\'      # 使用反斜線作為分隔字元（需要寫成 "\\"）
print(connect.join(path))
# 結果：D:\ch6\ch6_49.py

connect = '*'        # 使用一般字元作為分隔字元
print(connect.join(path))
# 結果：D:*ch6*ch6_49.py

s = "hello python"

# find()：從左邊找子字串，找不到回傳 -1
print(s.find("o"))     # 4

# rfind()：從右邊找最後一次子字串，找不到回傳 -1
print(s.rfind("o"))    # 10

# index()：找子字串位置，找不到會報錯
print(s.index("h"))    # 0

# rindex()：從右邊找最後一次，找不到會報錯
print(s.rindex("o"))   # 10

# count()：計算子字串出現次數
print(s.count("o"))    # 2

# isalnum()：判斷是否都為字母或數字
print("abc123".isalnum())  # True

# startswith()：是否以某字串開頭
print(s.startswith("hello"))  # True

# endswith()：是否以某字串結尾
print("hello.py".endswith(".py"))  # True

# replace()：將 ch1 替換成 ch2，產生新字串
print(s.replace("hello", "hi"))  # "hi python"

msg = '''CIA Mark told CIA Linda that the secret USB had given to CIA Peter'''
print("字串開頭是CIA: ", msg.startswith("CIA"))
print("字串結尾是CIA: ", msg.endswith("CIA"))
print("CIA出現的次數: ",msg.count("CIA"))
msg = msg.replace('Linda','Lxx')
print("新的msg內容 : ", msg)

# === ch6_51.py 使用 in / not in 判斷字元是否在字串內 ===
password = 'deepmind'
ch = input("請輸入字元 = ")

# in：如果 ch 在 password 這個字串內，回傳 True
print("in運算式")
if ch in password:
    print("輸入字元在密碼中")
else:
    print("輸入字元不在密碼中")

# not in：如果 ch 不在 password 中，回傳 True
print("not in運算式")
if ch not in password:
    print("輸入字元不在密碼中")
else:
    print("輸入字元在密碼中")


# === ch6_52.py 使用 in 檢查串列是否已有該水果 ===
fruits = ['apple', 'banana', 'watermelon']
fruit = input("請輸入水果 = ")

# 如果水果已經在串列裡 → 不新增
if fruit in fruits:
    print("這個水果已經有了")
else:
    # 如果沒有 → 新增到串列中
    fruits.append(fruit)
    print("謝謝提醒已經加入水果清單: ", fruits)

x = 10
y = 10
#他們的id會一樣是因為 Python 對 小整數（-5 ～ 256）做快取（integer caching）→ 同樣的數字會共用同一個物件
# === ch6_53.py 整數與記憶體位址 ===
x = 10
y = 10
z = 15
r = 20

# Python 會快取 -5~256 的整數，數字相同 → 位址也相同
print(id(x), id(y), id(z), id(r))

r = x  # r 指向與 x 相同的物件 10
print(id(x), id(r))  # 兩者位址完全相同


# === ch6_54.py is / is not 用在整數 ===
x = 10
y = 10
z = 15
r = z - 5  # r = 10，因此 r 與 x、y 同位址（整數快取）

print(x is y)       # True
print(x is z)       # False
print(x is r)       # True
print(x is not y)   # False
print(x is not z)   # True
print(x is not r)   # False


# === ch6_55.py is / is not 用在串列 ===
mysports = ['basketball', 'baseball']
sports1 = mysports      # 賦值 → 同位址（同物件）
sports2 = mysports[:]   # 切片拷貝 → 新物件（不同位址）

print(id(mysports), id(sports1))  # 相同位址
print(id(mysports), id(sports2))  # 不同位址

print(mysports is sports1)        # True
print(mysports is sports2)        # False
print(mysports is not sports1)    # False
print(mysports is not sports2)    # True

# enumerate()：將可迭代物件加上索引，回傳 enumerate 物件（迭代器）

drinks = ["coffee", "tea", "wine"]

# 建立 enumerate 物件，索引從 0 開始
enumerate_drinks = enumerate(drinks)

print(enumerate_drinks)         # 印出 enumerate 物件的位置
print(type(enumerate_drinks))   # <class 'enumerate'>

# 將 enumerate 物件轉成串列 → 得到 (索引, 值) 的 tuple
print(list(enumerate(drinks)))  
# [(0, 'coffee'), (1, 'tea'), (2, 'wine')]

# 指定起始索引為 10
print(list(enumerate(drinks, start=10)))
# [(10, 'coffee'), (11, 'tea'), (12, 'wine')]
