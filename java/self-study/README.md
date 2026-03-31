# Java 自學筆記

這個資料夾是**個人自學用**，與學校課程作業完全分開。

## 使用方式

```bash
# 編譯單一檔案
javac HelloWorld.java

# 執行
java HelloWorld
```

## 資料夾規則

- 每個主題或概念建立一個 `.java` 檔，檔名用 `PascalCase`
- **不需要加 `package` 宣告**（和學校作業不同）
- 可以依主題建立子資料夾，例如：`basics/`、`oop/`、`collections/` 等

## 建議學習順序

1. `HelloWorld.java` — 基本輸出
2. 變數、型別、運算子
3. 條件判斷 (`if`/`switch`)
4. 迴圈 (`for`/`while`)
5. 陣列
6. 方法 (Method)
7. 物件導向 (Class / Object)
8. 繼承、介面
9. 集合框架 (`ArrayList`, `HashMap`)
10. 例外處理 (`try-catch`)

## 個人筆記
# Chapter 3 重點知識清單
Class & Object：

Class = template（模板），Object = instance（實體）
用 new 關鍵字來 instantiate（實體化）物件
每個物件有自己獨立的一份 instance variable

Encapsulation（封裝）：

Instance variable 用 private，method 用 public
透過 set/get methods 存取 private 資料
目的：data hiding + 可以在 set method 加驗證邏輯

命名慣例：

Class → Upper CamelCase（StudentRecord）
Method/Variable → lower camelCase（setName, myAccount）

Instance Variable vs Local Variable：

Instance variable：class 裡面、method 外面，有預設值
Local variable：method 裡面，沒有預設值，不初始化會編譯錯誤
Parameter 也算 local variable

預設值：

數字型：0 或 0.0
boolean：false
Reference type（含 String）：null

Constructor：

名稱必須跟 class 一樣，不能寫回傳型別
被 new 自動呼叫
沒寫任何 constructor → Java 提供 default constructor
自己寫了 constructor → 沒有 default constructor 了

Primitive vs Reference Type：

Primitive：直接存值（8 種：boolean, byte, char, short, int, long, float, double）
Reference：存物件的地址

Literal：

整數預設 int，浮點數預設 double
long 加 L，float 加 F
float x = 0.5; ❌，float x = 0.5F; ✅
long x = 5000000000; ❌，long x = 5000000000L; ✅

型態轉換：

自動轉型：小轉大（安全）
強制轉型：大轉小，用 (型別)值，截斷不四捨五入

Scanner：

nextLine() → 讀整行
next() → 讀到空白停
nextDouble() → 讀 double

其他：

static method 不需要物件就能呼叫，main 必須是 static
同 package 的 class 不需要 import
用 fully qualified name 也不需要 import
PATH 找工具，CLASSPATH 找 .class 檔案
%.2f 顯示小數點後兩位

完全正確！

A 和 B ✅ 可以共存：parameter 型別不同（int vs double），合法的 overloading
A 和 C ❌ 不能共存：parameter list 完全一樣（都是 int x），只有 return type 不同（void vs int），編譯錯誤


# Chapter 6 重點知識清單
static 相關：

static method 不需要物件就能呼叫，用 ClassName.methodName() 呼叫
static method 不能直接存取 instance variable 和 instance method，必須透過物件
static variable（class variable）全 class 共用一份
main 是 static 因為 JVM 啟動時還沒有任何物件
fields = static variables + instance variables

Math 類別：

全部都是 static method，不需要 new Math()
ceil 往正方向取整、floor 往負方向取整，對負數要小心
Math.PI 和 Math.E 是 public static final 常數

final 關鍵字：

final = 常數，只能設定一次
static final 欄位要在宣告時或 static initializer block 裡給值

Argument Promotion：

小轉大自動提升，大轉小需要 cast
boolean 完全不參與數值型別轉換
char 不能跟 short/byte 互轉

SecureRandom 亂數：

nextInt(n) 回傳 0 到 n-1
公式：shiftingValue + obj.nextInt(scalingFactor)
scalingFactor = 最大值 - 最小值 + 1

enum：

特殊的 class，定義一組固定常數
不能把 int 賦值給 enum 變數（跟 C++ 不同）
常數用全大寫命名
switch 的 case 裡不加類別名

Scope：

local variable scope：宣告處到 block 結束
for 迴圈變數 scope：只在 for 內
field scope：整個 class body
shadowing：local variable 同名會遮蔽 field，用 this 存取被遮蔽的 field

Method Overloading：

同名不同 parameter list
signature = 名稱 + parameter 數量/型別/順序
return type 不是 signature 的一部分，不能只靠 return type 區分