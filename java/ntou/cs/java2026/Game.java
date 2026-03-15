package ntou.cs.java2026;

public class Game {
	public static void main(String[] args) {
		Player player1 = new Player();
		Player player2 = new Player();
		System.out.printf("Player 1 -> HP: %,d, Attack: %,d%n",
				player1.getHp(), player1.getAttackPoints());
		System.out.printf("Player 2 -> HP: %,d, Attack: %,d%n",
				player2.getHp(), player2.getAttackPoints());
		System.out.println();

		while (true) {
			player1.attack(player2);
			System.out.printf("Player 1 attacks Player 2's HP becomes %,d%n", player2.getHp());

			if (player2.getHp() == 0) {
				System.out.println("Player 1 wins!");
				break;
			}

			player2.attack(player1);
			System.out.printf("Player 2 attacks Player 1's HP becomes %,d%n", player1.getHp());

			if (player1.getHp() == 0) {
				System.out.println("Player 2 wins!");
				break;
			}

			System.out.println();
		}
	}
}