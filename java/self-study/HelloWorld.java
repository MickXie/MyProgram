
// =======================================
// NTOU Java 2026 — 考前複習筆記
// =======================================

// ── Q1：編譯指令 ──
// javac HelloWorld.java
// 注意：若不在同個目錄，要寫完整路徑
// 例：javac /Users/xiaom/Desktop/.../HelloWorld.java

// ── Q2：執行指令 ──
// java HelloWorld
// 同上，要在 .class 所在目錄，或用 -cp 指定路徑

// ── Q3：帶 package 和 jar 的編譯指令（Exercise 2-2 必考）──
// 站在 java/ 目錄下執行（jsoup jar 也在這裡）：
// javac -d . -cp jsoup-1.22.1.jar ntou/cs/java2026/BookParserTest.java
//
// 解析：
//   -d .         → 在「當前目錄」自動建立 ntou/cs/java2026/ 資料夾
//   -cp xxx.jar  → 告訴編譯器去哪裡找 jsoup 函式庫
//   最後接 .java 檔案路徑（可以是相對或絕對路徑）

// ── Q4：帶 package 和 jar 的執行指令（Exercise 2-2 必考）──
// java -cp .:jsoup-1.22.1.jar ntou.cs.java2026.BookParserTest
//
// 解析：
//   -cp .:jsoup-1.22.1.jar  → . 是當前目錄（.class 在這），: 是分隔符（Mac/Linux 用 :，Windows 用 ;）
//   ntou.cs.java2026.BookParserTest  → fully qualified name（package名.類別名）
//   ！注意：不是 / 是 .，不加 .class

// ── Q5：命名規則 ──
// 類別名稱必須用 CamelCase（大寫開頭），且「檔名必須和 public class 名稱完全一樣」
// 例：public class BookParser → 檔名必須是 BookParser.java

// ── Q6：Package 是什麼？──
// package 就像「資料夾路徑」，用來組織和區分類別
// 宣告放在「檔案第一行」（比 import 還早）：
//   package ntou.cs.java2026;
//
// 有了 package 之後：
//   - 執行時要用 fully qualified name（Q4 那樣）
//   - 編譯時 -d . 會自動建立對應的目錄結構 ntou/cs/java2026/
//   - 同一個 package 內的類別可以直接互相呼叫
//   - 不同 package 要用 import 才能用

// ── Q7：output 輸出雙引號（不能增加行數）──
// output 要同時包含學號、姓名、換行、雙引號：
// String output = "學號：\"01357043\"\n姓名：\"你的名字\"";
//
// 解析：
//   \" = 跳脫字元，代表雙引號 "
//   \n = 換行

// ── Q8：hp 和 attackPoints 的欄位宣告 ──
// private long hp;         → long 因為數字超過 int 上限（>21億）
// private int attackPoints;

// ── Q9：setHp 的邏輯 ──
// public void setHp(long newHp) {
//     if (newHp < 0) {
//         this.hp = 0;
//     } else {
//         this.hp = newHp;
//     }
// }

// ── Q10：nextFloat() 亂數公式（只能用 nextFloat，不能用 nextInt）──
// hp 範圍：9,000,000,000 ~ 9,999,999,999
// this.hp = 9_000_000_000L + (long)(random.nextFloat() * 1_000_000_000L);
// attackPoints 範圍：100,000,000 ~ 199,999,999
// this.attackPoints = 100_000_000 + (int)(random.nextFloat() * 100_000_000);
//
// 公式：min + (type)(nextFloat() * 範圍大小)
// 重要：9_000_000_000 後面要加 L，因為超過 int 範圍！

// ── Q11：attack 方法 ──
// public void attack(Player enemy) {
//     long newHp = enemy.getHp() - this.attackPoints;
//     enemy.setHp(newHp);  // setHp 會自動處理負數問題
// }

// ── Q12：千位逗號格式 ──
// System.out.printf("HP: %,d%n", player1.getHp());
// %,d → 整數加千位逗點（例：9,123,456,789）
// %n  → 換行（printf 裡用 %n，不用 \n）

// ── Q13：勝負判斷用 == 0 而不是 <= 0 ──
// 因為 setHp 已保證 hp 不可能 < 0，所以 == 0 和 <= 0 等效

// ── Q14：字串比較用 .equals() 不用 == ── 
// == 比較記憶體位址（reference），.equals() 比較內容
// face.equals(DeckOfCards.FACES[0])  → 正確
// face == DeckOfCards.FACES[0]       → 錯誤！

// ── Q15：Card 點數規則 ──
// FACES[0] = Ace → 20 點
// FACES[1] = Deuce(2) → 2 點
// ...
// FACES[9] = Ten → 10 點
// FACES[10] = Jack → 11 點
// FACES[11] = Queen → 12 點
// FACES[12] = King → 13 點

// ── Q17：Shallow Copy vs Deep Copy ──
// Shallow Copy：複製 reference，兩個變數指向同一個物件
//   myDeckOfCards = game.myDeckOfCards;  ← shallow copy
// Deep Copy：建立全新的獨立物件（這次作業不需要）

// ── Q20：Complex 的 SecureRandom（Exercise 4）──
// import java.security.SecureRandom;
// SecureRandom random = new SecureRandom();
// this.real = random.nextDouble();  // 0.0 ~ 1.0

// ── Q21：複數乘法公式 ──
// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
// newReal      = a*c - b*d
// newImaginary = a*d + b*c

// ── Q22：toString 處理負虛部 ──
// if (imaginary >= 0) → "%.2f + %.2fi"
// else                → "%.2f - %.2fi"（用 -imaginary 取絕對值）

// ── Q23：ComplexNumberCalculator 演算法 ──
// 1. 驗證輸入（null / 空矩陣 / null行 → IllegalArgumentException）
// 2. 每行所有複數加總（初始值 new Complex(0,0)）
// 3. 所有行的加總結果相乘（初始值 new Complex(1,0)）

// ======= 以下是自學練習程式碼 =======

public class HelloWorld {
    public static void main(String[] args) {
        // 輸出後換行
        System.out.println("Hello, World!");

        // 輸出後不換行
        System.out.print("Hello");
        System.out.print(" World"); // → Hello World
        System.out.println();

        // 格式化輸出（類似 C 的 printf）
        System.out.printf("名字：%s，年齡：%d%n", "Alice", 20);

        // 基本資料型態
        int age = 20;
        double price = 99.9;
        char grade = 'A';
        boolean isPassed = true;
        long population = 8_000_000_000L; // L 後綴代表 long
        float pi = 3.14f;                 // f 後綴代表 float，預設是 double

        // 千位逗號格式
        System.out.printf("人口：%,d%n", population); // → 8,000,000,000
    }
    public class Time1 {
        private int hour; // 0-23
        private int minute; // 0-59
        private int second; // 0-59

        public void setTime(int hour, int minute, int second) {
            if (hour < 0 || hour >= 24 ||
                    minute < 0 || minute >= 60 ||
                    second < 0 || second >= 60)
                throw new IllegalArgumentException(
                        "hour, minute and/or second was out of range");
            this.hour = hour;
            this.minute = minute;
            this.second = second;
        }

        public String toUniversalString() {
            return String.format("%02d:%02d:%02d", hour, minute, second);
        }

        public String toString() {
            return String.format("%d:%02d:%02d %s",
                    ((hour == 0 || hour == 12) ? 12 : hour % 12),
                    minute, second, (hour < 12 ? "AM" : "PM"));
        }
    }
}
