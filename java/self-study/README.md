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

---

## 🎉 Chapter 7 Part 1 全部完成！

這份 PDF 69 頁全部教完了。我幫你整理這章的**重點知識清單**：

### Chapter 7 你已掌握的重點：

- Array 是物件（reference type），建立後**長度固定**（`final length`）
- `array.length`（field，無括號）vs `String.length()`（method，有括號）
- Index 只接受 `int`/`byte`/`short`/`char`，**`long` 不行**
- 用 `new` 建立：`new int[10]`；用 initializer list：`{1,2,3}` 只能在宣告同行用
- 分開寫要用 `new int[]{1,2,3}`
- 陣列元素一定有預設值（數值→0、boolean→false、reference→null），即使是 local variable 參考的陣列
- `ArrayIndexOutOfBoundsException`：index 超出範圍（Java 自動做 bounds checking，C++ 不會）
- `NullPointerException`：對 null 呼叫方法
- try-catch 處理例外，try 裡的 local variable 在 catch 裡 out of scope
- 物件陣列 `new Card[52]` 只建立 52 個 null reference，不是 52 個物件
- `toString()` 是 Object 的 method，`println` 和 `+` 串接時自動呼叫
- Enhanced for：只能讀不能改、沒有 index
- **Java 全部都是 pass-by-value**：傳 reference type 時複製的是 reference，可以改內容但不能改指向
- 二維陣列本質是「陣列的陣列」，允許 ragged array（每 row 長度不同）
- `new int[2][]` ✅、`new int[][3]` ❌（必須先指定 row）
- `array.length` = row 數、`array[row].length` = 該 row 的 column 數

---

要我出一份這章的模擬測驗嗎？還是你要傳下一章的 PDF 繼續？

好的！這是更新後的已完成章節記錄，把 Chapter 7 Part 2 加進去了：

---

### Chapter 7 Part 2 我已掌握的重點：

**Variable-Length Argument Lists（varargs）**
- 語法：`type... varName`，在 method 內當陣列用（有 `.length`，可以 enhanced for）
- `...` 只能放在 parameter list **最後面**，一個 method 只能有**一個** varargs
- 呼叫時直接傳個別值，Java 自動包成陣列；也可以傳陣列
- `int[]` vs `int...`：method 內部一樣，差別在呼叫端；`int[]` 必須傳陣列物件，`int...` 可以傳個別值

**Command-Line Arguments**
- `main(String[] args)` 接收命令列參數，全部都是 **String**
- 要用數字必須 `Integer.parseInt()` 或 `Double.parseDouble()` 轉換
- 參數用**空白**分隔，`args.length` 取得數量
- 不給參數時 `args.length` 是 **0**，不是 null

**Class Arrays**（需要 `import java.util.Arrays`）
- `Arrays.sort(arr)` — 升冪排序，**直接修改原陣列**，不回傳新陣列
- `Arrays.fill(arr, value)` — 全部填同一個值
- `Arrays.equals(a, b)` — 比較**內容**，回傳 boolean；不能用 `==` 或 `.equals()`（那是比較 reference）
- `Arrays.binarySearch(arr, value)` — 找到回傳 index（≥0），找不到回傳負數；**使用前必須先 sort**，否則是 logic error
- `System.arraycopy(src, srcPos, dest, destPos, length)` — 複製陣列，目標陣列要先 `new` 好

**Collections & Class ArrayList**（需要 `import java.util.ArrayList`）
- 動態大小，可以隨時新增刪除元素
- Generic class：型別參數只能用 **reference type**，`int` 要用 `Integer`
- Diamond `<>` 語法：`new ArrayList<>()` 讓編譯器自動推斷型別（Java SE 7+）
- capacity vs size：capacity 是內部空間，size 是實際元素數量；空間滿了才擴張
- `add(value)` 加到最後、`add(index, value)` 插入指定位置
- `get(index)` 取元素、`remove(value)` 刪值、`remove(index)` 刪位置
- `size()` **有括號**（vs array 的 `length` 無括號）
- `contains(value)` 回傳 boolean、`clear()` 清空、`trimToSize()` 縮減 capacity

**Labeled break**
- 普通 `break` 只跳出**最內層**迴圈或 switch
- `break 標籤名稱` 跳出**外層**指定的 statement
- label 寫在要跳出的 statement **前面**，格式：`標籤名稱:`

**Map and HashMap**（需要 `import java.util.HashMap`）
- Key-value 配對，key **不能重複**（重複會直接覆蓋，不報錯）
- `put(key, value)` 新增或覆蓋、`get(key)` 取值
- `get()` 找不到 key 回傳 **null**，不報錯
- `containsKey(key)` 回傳 boolean、`remove(key)` 刪除、`size()` 取數量
- 型別參數只能用 reference type，`int` 要用 `Integer`

---

把這段複製貼到你的 CLAUDE.md 的「已完成章節」區塊裡，下一個對話就能無縫銜接了！

## 📚 Chapter 8 重點整理（目前進度：第1-64頁）

---

### 8.2 Time Class & Throwing Exceptions

```java
// throw 語法
throw new IllegalArgumentException("錯誤訊息");
```

| 重點 | 說明 |
|------|------|
| `throw` 後 method 立刻停止 | 後面的程式碼不執行 |
| 呼叫端用 `try-catch` 接 | 沒有 catch → 程式崩潰 |
| 是編譯期還是執行期？ | **執行期**才丟出 |
| `%02d` | 至少2位數，不足補0 |

---

### 8.3 Access Control

| 修飾字 | 同class | 同package | 子類別 | 其他 |
|--------|---------|-----------|--------|------|
| `public` | ✅ | ✅ | ✅ | ✅ |
| `private` | ✅ | ❌ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ✅ | ❌ |
| 無修飾字 | ✅ | ✅ | ❌ | ❌ |

⭐ 從另一個 class 存取 `private` field → **編譯錯誤**

---

### 8.4 this Reference

**兩種用法：**

```java
// 用法一：區分 field 和 parameter
this.hour = hour;

// 用法二：呼叫同一個 class 的另一個 constructor
this(0, 0, 0);  // 必須在第一行！
```

⭐ **static method 不能用 `this`** → 編譯錯誤

---

### 8.5 Overloaded Constructors

```java
public Time2() { this(0, 0, 0); }           // 無參數
public Time2(int hour) { this(hour, 0, 0); } // 一個參數
public Time2(int hour, int minute) { this(hour, minute, 0); } // 兩個參數
public Time2(int hour, int minute, int second) { /* 實際做事 */ } // 三個參數
public Time2(Time2 time) { this(time.getHour(), time.getMinute(), time.getSecond()); } // copy constructor
```

**`this()` 的三條規則：**

| 規則 | 說明 |
|------|------|
| 只能在 constructor 裡用 | 一般 method 不能呼叫 |
| 必須在**第一行** | 不是第一行 → 編譯錯誤 |
| 只能呼叫同一個 class | 不能跨 class |

⭐ **`private` 界線是 class，不是 object**
```java
// 同一個 class 裡，可以存取另一個物件的 private field
public Time2(Time2 other) {
    this.hour = other.hour;  // ✅ 合法
}
```

---

### 8.6 Default & No-Argument Constructor

⭐⭐ **最容易考的陷阱：**

```java
// 情況一：沒寫任何 constructor
// → 編譯器自動給 default constructor
// → new MyClass() ✅

// 情況二：自己寫了有參數的 constructor
// → 編譯器【不再】給 default constructor
// → new MyClass() ❌ 編譯錯誤！

// 情況三：自己寫了有參數的，也補寫無參數的
// → new MyClass() ✅
// → new MyClass(10) ✅
```

---

### 8.7 Set and Get Methods

| 比較 | `public` field | `private` + set/get |
|------|---------------|---------------------|
| 封裝 | ❌ | ✅ |
| 驗證 | ❌ | ✅ |

⭐ **兩個理由用 private + set/get：**
1. 封裝原則（隱藏內部實作）
2. 可以阻擋不合法的值

⭐ **class 的 field 不應該是 public（除非是常數）**
```java
public static final double PI = 3.14159;  // ✅ 常數可以 public
public int hour;                           // ❌ 不好
```

⭐ **已經有 setXXX 就不要直接存取 field：**
```java
// ❌ 不好
hour = 0;

// ✅ 好
setHour(0);  // 確保驗證邏輯一定執行
```

---

### 8.8 Composition

> **has-a 關係**：一個 class 的 field 是另一個 class 的物件

```java
public class Employee {
    private Date birthDate;  // ← Composition
    private Date hireDate;   // ← Composition
}
```

⭐ **`%s` 或 `+` 遇到物件，自動呼叫 `toString()`**

⭐ **`String.format` vs `printf`：**
| | 回傳 | 用途 |
|---|---|---|
| `String.format` | String | 在 `toString()` 裡 return |
| `printf` | 無 | 直接印出 |

---

### 8.9 enum Types

```java
// 基本版
public enum Day {
    MONDAY, TUESDAY, WEDNESDAY
}

// 帶值版
public enum Day {
    MONDAY("平日"), SATURDAY("假日");  // ← 分號！

    private String type;
    Day(String type) { this.type = type; }
    public String getType() { return type; }
}
```

⭐ **enum 是 reference type，不能把 int 賦值給 enum（跟C++不同）**

⭐ **switch 的 case 裡不用加類別名：**
```java
case MONDAY:   // ✅
case Day.MONDAY:  // ❌
```

---

### 8.10 Garbage Collection

| 重點 | 說明 |
|------|------|
| 沒有變數指向物件 | 變成垃圾，等待 GC |
| GC 執行時機 | **不保證**，可能程式結束前都不執行 |
| `finalize()` | 已廢棄，**不要用** |
| 釋放資源 | 用 `close()`/`dispose()` 或 try-with-resources |
| Java vs C++ | Java 自動 GC，C++ 要手動 `delete` |

---

### 8.11 static Class Members

⭐⭐ **static vs instance 比較：**

| | static | instance |
|---|---|---|
| 屬於 | 整個 class | 每個物件 |
| 幾份 | **一份**，共用 | 每個物件各一份 |
| 存取方式 | `ClassName.member` | `object.member` |
| 可以用 `this` | ❌ | ✅ |
| 可以存取 instance variable | ❌ | ✅ |

⭐ **static method 的限制：**
```java
public static void test() {
    System.out.println(count);       // ✅ static variable OK
    System.out.println(firstName);   // ❌ instance variable → 編譯錯誤
    System.out.println(this.firstName); // ❌ this → 編譯錯誤
}
```

⭐ **String 是 immutable：**
```java
String s1 = "Hello";
String s2 = s1 + " World";  // s1 沒有被改變，產生新的 String 物件
```

---

## ⚠️ 還沒教的部分

| 頁數 | 主題 |
|------|------|
| 65-68 | 8.12 static Import |
| 69-74 | 8.14 Package Access |

---

還有兩個主題沒教完，繼續嗎？

static = 屬於類別 (class)，不是屬於物件 (object)
java執行程式時從mian但main沒有物件故需要static讓他能直接執行main

print 不換行繼續印
println 換行印
printf 可以放%d%s之類的
補:%n換行,輸入一個字串換行%s%n

Scanner是一個類別 
Scanner input(變數名稱) = new Scanner(System.in)
Scanner用來讀取輸入 
input 是輸入的變數 
new 表新建立一個物件 
Scanner(…)呼叫Scanner的建構子 
也就是： 建立一個叫做 input 的物件， 這個物件是用 Scanner 類別做出來的， 並且讓它去讀取 System.in（鍵盤輸入）。 

.nextInt() 轉成整數型態 

Import不等於Include 
Import可以讓程式裡的類別內容例如Scanner 全名是Java.util.Scanner加了 import java.util.Scanner 就可以只寫Scanner 

java.lang例如：java.lang.System不需要import java會自己做 
可以寫這樣例：import.java.lang.*會包含全部 

Long要用l或L結尾 例：1000000000L 
Float要用F,f結尾 
Double要用D,d結尾 
浮點數以double(整數以int為主)為主後面不加d不會錯但宣告float後面一定要加f
整數可轉浮點數，反過來不行
只能例:x = int(10.5)
long x = 100無誤差
double x = 5.4f 可能有誤差
整數轉浮點float x = 500000f;可能有誤差

input.next()
只讀到下一個空白前的內容。
input.nextLine()
會讀取整整一行，直到你按 Enter 為止。

有自己設定的建構子就要填好裡面的東西不能new空的 例：
public class Account { 
public Account(string name){ 
這裡面就是 
} 
} 
這個建構子他不會回傳任何值 

javac -d . *.java快速建立你所設定的package ，裝package執行要用全名
若要自行把函式庫裝進你的專案裡，指令:
Javac -classpath .;(檔案名稱) -d . (-d.若有package)*.java
執行時:
Java -classpath .;(檔案名稱) (類別名稱)
適用於小型函示庫

@Override繼承父類，如果有拼錯會報錯防止你引用到錯誤的函數

throws IOException抓網頁如果抓網頁失敗可能丟出 IOException

break直接中斷此迴圈continue中斷目前迴圈

final只能給值一次之後不能更改

一般物件類型的函式，需要有一個具體物件才可以呼叫，static可以讓韓式變成類別型態可以不用一個具體的物件就能呼叫

亂數:import.java.security.SecureRandom
Private static final SecureRandom randomNumbers(變數名稱) = new SecureRandom();
.nextInt(6):0-5

列舉固定型態:
Public/private enum dice(變數名稱) {1,2,3,4,5,6};

標準化數字格式100000->100,000
import java.text.NumberFormat;
NumberFormat nf = NumberFormat.getInstance();
nf.format(變數)

class用來宣告類別 只有一開始用 類別裡的方法不需要class 
沒有static的方法 我在自己的類別中想呼叫 要先用自己的類別創建一個物件才可以使用 
宣告陣列： int c[]; 
c = new int[12]; 
要設定好才能用： 
int [] c = new int[12]; 
給值： int[] c = {0,1,2,3}; 
陣列new完長度固定 

例外處理： 
try{ 
    程式主邏輯 
    throw new NullPointerException();
｝ 
catch(例外物件）{ 
    Handle
} 

印物件compiler會補.toString，我們可以藉由@Override去改寫Object的toString來達到我們希望的輸出樣子

Enhance:
Int [] array = {10,20,32,56,41,82};
for(int (變數)number : array){
    主程式;
}
他會跑六次，每次把array的元素照順序站存到number

陣列丟進方法裡(int[] array)丟的是本人出來會變
陣列丟進方法裡(int element)丟的是值出來原本不會改變
若是類別型態算是reference改了會變

多維
Int[][]b = {{1,2},{3,4}};

This可以用來呼叫另一個建構子
Public class time{
    Private int hour;
    Private int minute;
    Private int second;
    Public time(){
        This(0,0,0);
    }
    Public time(int hour){
        This(hour,0,0);
    }

Public time(Time time){ DeepCopy
    This(time.getHour(), time.getMinute(), time.getSecond());
}