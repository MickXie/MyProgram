
// 自學 Java 起點
// 不需要 package，直接執行即可
// 編譯：javac HelloWorld.java
// 執行：java HelloWorld
import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // 輸出後換行
        System.out.println("Hello, World!");
        String name = scanner.nextLine(); // 讀取一行字串
        int age = scanner.nextInt(); // 讀取一個整數
        // 輸出後不換行
        System.out.print("Hello");
        System.out.print(" World"); // → Hello World

        // 格式化輸出（類似 C 的 printf）
        System.out.printf("名字：%s，年齡：%d%n", "Alice", 20);
        System.out.printf("名字：%s，年齡：%d%n", name, age);
        scanner.close();

        int ages = 20;
        double price = 99.9;
        char grade = 'A';
        boolean isPassed = true;
        long population = 8000000000L; // L 後綴代表 long
        float pi = 3.14f; // f 後綴代表 float 默認位double

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
