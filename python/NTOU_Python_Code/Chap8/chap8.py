#元組的定義
#➢mytuple = (元素1, … , 元素n,) # mytuple是假設的元組名稱
#➢如果元組內的元素只有一個，在定義時需在元素右邊加上逗號(“,”)
#✓mytuple = (元素1,) # 只有一個元素的元組
#mytuple[i] # 讀取索引i的元組元素似陣列
#tuplE唯讀,股修改元組元素➢用重新定義方式修改元組元素內容
#不可append不可del
#可轉化成list,enumerate
#enumerate也可轉為tuple但是會多一組資料->index
# zip() 將多個可迭代物件一對一打包
# fields 與 info 的第 i 個元素會組成一組 tuple

fields = ['Name', 'Age', 'Hometown']
info   = ['Peter', '30', 'Chicago']

zipData = zip(fields, info)     # 建立 zip 物件（拉鍊式配對）
print(type(zipData))            # zipData 是 zip 類型，不是串列

player = list(zipData)          # 將 zip 物件轉成串列，方便查看內容
print(player)                   # 每筆是 (欄位, 資料) 的 tuple
