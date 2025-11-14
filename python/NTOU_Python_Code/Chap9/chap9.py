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
