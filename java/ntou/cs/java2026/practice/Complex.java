package ntou.cs.java2026.practice;

import java.security.SecureRandom;

// Exercise 4 — 題目要求：
// 實作複數（Complex Number）類別
// 支援加、減、乘、絕對值，以及格式化輸出

public class Complex {

    // TODO 1: 宣告兩個 private double 欄位：real、imaginary


    // TODO 2: 雙參數建構子 Complex(double real, double imaginary)
    public Complex(double real, double imaginary) {

    }

    // TODO 3: 無參數建構子
    // 使用 SecureRandom 的 nextDouble() 隨機設定 real 和 imaginary（範圍 0.0 ~ 1.0）
    public Complex() {

    }

    // TODO 4: add(Complex other) — 回傳新的 Complex（各分量相加）
    public Complex add(Complex other) {
        return null;
    }

    // TODO 5: subtract(Complex other) — 回傳新的 Complex（各分量相減）
    public Complex subtract(Complex other) {
        return null;
    }

    // TODO 6: multiply(Complex other)
    // 公式：(a+bi)(c+di) = (ac - bd) + (ad + bc)i
    public Complex multiply(Complex other) {
        return null;
    }

    // TODO 7: abs() — 回傳 √(real² + imaginary²)
    public double abs() {
        return 0;
    }

    // TODO 8: toString()
    // 虛部 >= 0 → "1.00 + 2.00i"
    // 虛部 <  0 → "1.00 - 2.00i"（注意：用 -imaginary 取絕對值，不要印負號兩次）
    @Override
    public String toString() {
        return null;
    }
}
