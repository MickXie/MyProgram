package ntou.cs.java2026;

import java.util.Random;

public class Player {
    private long hp;
    private int attackPoints;

    public Player() {
        Random random = new Random();
        this.hp = 9_000_000_000L + (long) (random.nextFloat() * 1_000_000_000L);
        this.attackPoints = 100_000_000 + (int) (random.nextFloat() * 100_000_000);
    }

    public long getHp() {
        return hp;
    }

    public int getAttackPoints() {
        return attackPoints;
    }

    public void setHp(long newHp) {
        if (newHp < 0) {
            this.hp = 0;
        } else {
            this.hp = newHp;
        }
    }

    public void attack(Player enemy) {
        long newHp = enemy.getHp() - this.attackPoints;
        enemy.setHp(newHp);
    }
}