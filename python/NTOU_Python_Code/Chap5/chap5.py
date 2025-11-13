#age = input("請輸入年齡: ")
#if (int(age) < 20):
    #print("你年齡太小")
    #print("需年滿20歲才可以購買菸酒")
#age = input("請輸入年齡: ")
#print("輸出絕對值")
#num = input("請輸入任意整數值: ")
#x = int(num)
#if (int(x) < 0): x = -x
#print(f"絕對值是 {x}")
# ------------------------------------------
# 三元運算子（if...else 一行寫法）
# max_ = x if x > y else y
# 讀法：若 x > y → max_=x，否則 max_=y
# ------------------------------------------
#變數 = 值1 if 條件 else 值2
# ------------------------------------------
# 使用內建函式 max(), min()
# max(x, y) 回傳 x, y 中較大者
# min(x, y) 回傳 x, y 中較小者
# 變數加 _ 避免覆蓋內建函式名稱
# ------------------------------------------
x=10
y=5
max_ = x if x > y else y 
min_ = x if x < y else y
print("判斷輸入字元類別")
ch = input("請輸入字元 : ")[0]   # ← 只取第一個字元
if ord(ch) >= ord("A") and ord(ch) <= ord("Z"):
    print("這是大寫字元")
elif ord(ch) >= ord("a") and ord(ch) <= ord("z"):
    print("這是小寫字元")
elif ord(ch) >= ord("0") and ord(ch) <= ord("9"):
    print("這是數字")
else:
    print("這是特殊字元")
    # ord(ch) 會回傳 ch 的 Unicode 數值
# 但 ord() 只能接受「單一字元」
# 若輸入多字元會錯誤，因此需 ch = input(...)[0] 只取第一個字
flag = None
if not flag:
    print("尚未定義flag")
if flag:
    print("有定義")
else:
    print("尚未定義flag")
    # ------------------------------------------------------------
# None 的概念（Python 專用的「無值」表示法）
# ------------------------------------------------------------
# 1. None 是 Python 的特殊值，用來表示：
#    - 尚未設定的變數
#    - 沒有資料
#    - 空結果 / 無回傳值
#    - 不存在的狀態
#
# 2. None 不是 0、不是空字串 ""、不是 False，
#    但在「布林判斷」中會被視為 False。
#       bool(None) → False
#
# 3. 常用於：
#    - 變數預設值（flag = None）
#    - 表示函式沒有回傳值
#    - 檢查物件是否存在（if x is None）
#
# 4. 判斷是否為 None 要用：
#       if x is None:
#           ...
#    而不是：
#       if x == None:   # 不建議
#
# 5. 在條件判斷中：
#       if not x:      # x 若是 None，會進入這裡
#       if x:          # x 若是 None，不會進來
# ------------------------------------------------------------
# 範例：
# flag = None
# if not flag:
#     print("flag 尚未設定")   # 會印出
# ------------------------------------------------------------
