#fruits[‘水蜜桃’] # 用字典變數[‘鍵’]取得值
#mydict[鍵] = 值增加字典元素
#更改內容:重新宣告該元素
#del刪除del name_dict[鍵]
#ret_value = dictObj.pop(key[, default])
#找到 key → 刪除該項目，並把它的 value 回傳
#找不到 key → 回傳 default（如果有給）
#找不到 key，而且沒有 default → 產生 KeyError 錯誤
fruits = {'西瓜':15, '香蕉':20, '水蜜桃':25}
print("舊fruits字典內容:", fruits)
# popitem():
# - 刪除字典中最後插入的那一組鍵值對
# - 同時回傳 (key, value) 的 tuple
# - 若字典為空，會產生 KeyError
valueTup = fruits.popitem()
print("新fruits字典內容:", fruits)   # 刪除最後一筆後的字典
print("刪除內容:", valueTup)         # 顯示被刪除的 (key, value)

#使用clear( )方法刪除fruits字典的所有元素
#➢del mydict 刪掉整個字典

#宣告空的字串name_dict = { }
#new_dict = mydict.copy( ) 複製字典


fruits = {'西瓜':15, '香蕉':20, '水蜜桃':25, '蘋果':18}
noodles = {'牛肉麵':100, '肉絲麵':80, '陽春麵':60}
empty_dict = {}
print("fruits字典元素數量 = ", len(fruits)) #4
print("noodles字典元素數量 = ", len(noodles)) #3
print("empty_dict字典元素數量 = ", len(empty_dict)) #0

# 可以使用in檢查元素是否在字典裡面
#在資料處理中我們可能會碰上雙值序列的資料，如下所示：
#✓[[‘日本’, ‘東京’], [‘泰國’, ‘曼谷’], [‘英國’, ‘倫敦’]]
#➢我們可以使用dict( )將此序列轉成字典，其中雙值序列的第一個是鍵，第二個是值
nation = [['日本','東京'],['泰國','曼谷'],['英國','倫敦']]
nationDict = dict(nation)
print(nationDict)

#for的使用:for name, team in players.items( ):第一個變數接鍵,第二個是值
#players.key()可以讓我們取得字典的鍵內容
#players.values( )遍歷字典的值

players = {
    'Stephen Curry':'Golden State Warriors',
    'Kevin Durant':'Golden State Warriors',
    'Lebron James':'Cleveland Cavaliers',
    'James Harden':'Houston Rockets',
    'Paul Gasol':'San Antonio Spurs'
}

# sorted(players.keys())：
# - players.keys() 取得所有字典的鍵（球員名字）
# - sorted() 依字母順序排序鍵
# - 使 for 迴圈能依排序後的順序遍歷字典

for name in sorted(players.keys()):
    print(name)    # 印出球員名字（已排序）
    print(f"Hi! {name} 我喜歡看你在 {players[name]} 的表現")  # 利用 key 查詢球隊並印出訊息

# --------------------------------------------------------------
# 說明：lambda item: item[1]
# --------------------------------------------------------------
# lambda 是 Python 的「匿名函式」語法（簡短的小函式，沒有名字）。
# 這段 lambda item: item[1] 的意思等同於以下函式：
#
#     def some_function(item):
#         return item[1]
#
# 也就是：接收一個參數 item，並回傳 item[1]（item 的第二個元素）。
#
# --------------------------------------------------------------
# 在 sorted(noodles.items(), key=lambda item: item[1]) 中：
# 1. noodles.items() 會產生由多個 (key, value) tuple 組成的列表，例如：
#       ('牛肉麵', 100)
#       ('肉絲麵', 80)
#       ('陽春麵', 60)
#
# 2. sorted() 在排序時，會把列表中的每一個元素（每一個 tuple）
#    依序傳入 key 所指定的函式，也就是 lambda item: item[1]
#
# 3. 因此第一次呼叫時：
#       item = ('牛肉麵', 100)
#       item[1] = 100
#    第二次呼叫時：
#       item = ('肉絲麵', 80)
#       item[1] = 80
#    第三次呼叫時：
#       item = ('陽春麵', 60)
#       item[1] = 60
#
# 4. sorted() 就會以這些回傳值（100、80、60）作為排序依據，
#    因此可以「依字典的價值 value 排序」。
#
# --------------------------------------------------------------
# 一句話總結：
# lambda item: item[1] 的作用是：
#    「從每一組 (key, value) 中取出 value 來作為排序的基準」。
# --------------------------------------------------------------

armys = [] # 建立小兵空串列
# 建立50個小兵
for soldier_number in range(50):
    if(soldier_number>35 and soldier_number<39):
        soldier = {'tag':'blue', 'score':5, 'speed':'medium'}
    else:
        soldier = {'tag':'red', 'score':3, 'speed':'slow'}
    armys.append(soldier)
# 列印前3個小兵
for soldier in armys[36:39]:
    print(soldier)
# 列印小兵數量
print("小兵數量 = ", len(armys))

# ------------------------------------------------------------
# 建立字典，其「鍵(key)」是球員名字，「值(value)」是一個「串列(list)」
# 每位球員可能喜歡多種運動，因此用串列來存他們的興趣
# ------------------------------------------------------------
sports = {
    'Curry': ['籃球', '美式足球'],
    'Durant': ['棒球'],
    'James': ['美式足球', '棒球', '籃球']
}

# ------------------------------------------------------------
# 使用 .items() 取得「鍵 與 值」的配對，並指定兩個變數接收
# name          → 球員名字（字典的 key）
# favorite_sport → 球員喜歡的運動（字典的 value，是一個串列）
# ------------------------------------------------------------
for name, favorite_sport in sports.items():
    print(f"{name} 喜歡的運動是：")

    # favorite_sport 是「串列」，因此內部還要再用 for 迴圈逐一印出
    for sport in favorite_sport:
        print("   ", sport)    # 在前面加空白讓排版更漂亮


# ------------------------------------------------------------
# 建立一個「巢狀字典 nested dictionary」
# 每一個帳號（key）對應到一個「字典」，這個字典包含名字、城市等資訊
# ------------------------------------------------------------
wechat_account = {
    'cshung': {                     # 第一個使用者帳號
        'last_name': '洪',          # 姓
        'first_name': '錦魁',        # 名
        'city': '台北'               # 城市
    },

    'kevin': {                      # 第二個使用者帳號
        'last_name': '鄭',
        'first_name': '義盟',
        'city': '北京'
    }
}

# ------------------------------------------------------------
# 遍歷整個字典，取得 key（帳號）與 value（內部字典）
# ------------------------------------------------------------
for account, info in wechat_account.items():
    print(f"帳號：{account}")

    # info 是一個字典，因此可用 key 取值
    print("姓氏：", info['last_name'])
    print("名字：", info['first_name'])
    print("城市：", info['city'])
    print("------------------------")  # 分隔線美觀

# ------------------------------------------------------------
# len( ) 用來計算「字典有多少個 key」
# 如果 value 也是字典，那它也可以用 len() 計算「內層字典的鍵數量」
# ------------------------------------------------------------

# 建立內含字典的字典（巢狀字典）
wechat_account = {
    'mark': {
        'last_name': '炭',
        'first_name': '志郎',
        'city': '台北'
    },
    'kevin': {
        'last_name': '豬',
        'first_name': '太郎',
        'city': '北京'
    }
}

# 外層字典有 2 個 key：mark、kevin
print("wechat_account 字典元素個數:", len(wechat_account))

# 內層字典，同樣可以算
print("mark 的資料筆數:", len(wechat_account['mark']))   # 有 3 個欄位
print("kevin 的資料筆數:", len(wechat_account['kevin'])) # 也是 3 個欄位


# ------------------------------------------------------------
# dict.fromkeys(seq, value)：
# 用 seq（串列或元組）裡的元素當作 keys，
# 並用 value 當作它們的預設值（可選）
# ------------------------------------------------------------

# 使用「串列」建立字典
seq1 = ['name', 'city']

list_dict1 = dict.fromkeys(seq1)  # 預設值 None
print("字典1:", list_dict1)       # {'name': None, 'city': None}

list_dict2 = dict.fromkeys(seq1, 'Chicago')
print("字典2:", list_dict2)       # {'name': 'Chicago', 'city': 'Chicago'}

# 使用「元組」建立字典
seq2 = ('name', 'city')

tup_dict1 = dict.fromkeys(seq2)
print("字典3:", tup_dict1)

tup_dict2 = dict.fromkeys(seq2, 'New York')
print("字典4:", tup_dict2)

# ------------------------------------------------------------
# dict.get(key, default)
# 取得 key 對應的值
# 若 key 不存在，回傳 default（預設是 None）
# 不會像 dict[key] 那樣出錯
# ------------------------------------------------------------

fruits = {'Apple': 20, 'Orange': 25}

ret_value1 = fruits.get('Orange')  # 找到 → 回傳 25
print("Value =", ret_value1)

ret_value2 = fruits.get('Grape')   # 找不到 → 回傳 None
print("Value =", ret_value2)

ret_value3 = fruits.get('Grape', 10)  # 找不到 → 回傳預設值 10
print("Value =", ret_value3)

# ------------------------------------------------------------
# dict.setdefault(key, default)
#
# 若 key 存在 → 回傳原本的值，不更動字典
# 若 key 不存在 → 新增 key，值為 default（預設為 None）
# ------------------------------------------------------------

fruits = {'Apple': 20, 'Orange': 25}

# key 'Orange' 已存在
ret_value = fruits.setdefault('Orange')
print("Value =", ret_value)       # 25
print("fruits 字典:", fruits)     # 不會改變

# 再給它 default 也沒用，因為 key 已存在
ret_value = fruits.setdefault('Orange', 100)
print("Value =", ret_value)       # 還是 25
print("fruits 字典:", fruits)

# ------------------------------------------------------------
# key 不存在，就會自動新增
# ------------------------------------------------------------

person = {'name': 'John'}
print("原先字典內容:", person)

age = person.setdefault('age')  # 新增 key='age', value=None
print("增加 age 鍵:", person)
print("age =", age)

sex = person.setdefault('sex', 'Male')  # 新增 key='sex', value='Male'
print("增加 sex 鍵:", person)
print("sex =", sex)
