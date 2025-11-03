# type( )函數 印出 變數的資料型態
x = 10
y = x / 3
print(x) 
print(type(x)) #<class 'int'>
print(y)
print(type(y)) #<class 'float'>
#整數使用時可以在數字中加上底線(_)
x =1_1_1 #x = 111
#Python具有簡單自動轉換能力
#2進位整數與函數bin( ) 可以將一般整數數字轉換為2進位。
#8進位整數與函數oct( )函數可以將一般數字轉換為8進位
#16進位整數與函數hex( )函數可以將一般數字轉換為16進位。
#int( )：將資料型態強制轉換為整數
#float( )：將資料型態強制轉換為浮點數
#abs( )：計算絕對值
#pow(x,y)：返回x的y次方
#round( )：這是採用演算法則的Bankers Rounding觀念
#當要四捨五入的位數「剛好是 .5」時： 若左邊是 奇數 → 進位（五入）若左邊是 偶數 → 不進位（五捨）
#字串(string)資料是指兩個單引號(‘)之間或是兩個雙引號(“)之間任意個數字元符號的資料 ->""裡面包含'的字串ex:"cc'dd"
#數學的運算子 ”+”，可以執行兩個字串相加，產生新的字串
#程式設計時如果字串長度多於一行，可以使用三個單引號(或是3個雙引號)將字串包夾即可
str1 = '''Silicon Stone Education is an unbiased organization
concentrated on bridging the gap ... '''
print(str1)
#\取消分行
str2 = '''Silicon Stone Education is an unbiased organization \
concentrated on bridging the gap ... '''
print(str2)
str3 = "Silicon Stone Education is an unbiased organization " \
"concentrated on bridging the gap ... "
print(str3)