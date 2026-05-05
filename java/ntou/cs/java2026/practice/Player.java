package ntou.cs.java2026.practice;

import java.util.Random;

// Exercise 3 — 題目要求：
// 實作一個 Player 類別，用來模擬遊戲角色
// hp 型態為 long（因為數值最大接近 10,000,000,000，超過 int 上限 2,147,483,647）
// attackPoints 型態為 int

public class Player {

    // TODO 1: 宣告兩個欄位
    // hp (long)、attackPoints (int)，皆為 private


    // TODO 2: 無參數建構子
    // 使用 Random 的 nextFloat() 隨機設定：
    //   hp 範圍：9,000,000,000 ~ 9,999,999,999
    //   attackPoints 範圍：100,000,000 ~ 199,999,999
    // 公式：min + (type)(random.nextFloat() * 範圍大小)
    // 注意：9_000_000_000 後面要加 L！
    public Player() {

    }

    // TODO 3: getter 方法
    public long getHp() {
        return 0; // 替換成正確實作
    }

    public int getAttackPoints() {
        return 0; // 替換成正確實作
    }

    // TODO 4: setHp(long newHp)
    // 若 newHp < 0，設為 0；否則設為 newHp
    public void setHp(long newHp) {

    }

    // TODO 5: attack(Player enemy)
    // 計算 enemy 的新 HP = enemy.getHp() - this.attackPoints
    // 呼叫 enemy.setHp() 更新（setHp 會自動處理負數）
    public void attack(Player enemy) {

    }
}
