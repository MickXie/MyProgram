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