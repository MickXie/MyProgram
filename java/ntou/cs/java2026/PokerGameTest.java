package ntou.cs.java2026;

import java.util.Scanner;

public class PokerGameTest {

	public static void main(String[] args) {
		PokerGame game = new PokerGame();
		Scanner input = new Scanner(System.in);

		int choice;

		while (true) {
			System.out.print("Please input your choice (0: quit, 1: play, 2: restart, 3: repeat): ");
			choice = input.nextInt();

			if (choice == 0) {
				System.out.println("Game over!!");
				break;
			} else if (choice == 1) {
				game.dealFiveCards();
			} else if (choice == 2) {
				game = new PokerGame();
				game.dealFiveCards();
			} else if (choice == 3) {
				game = new PokerGame(game);
				game.dealFiveCards();
			}
		}

		input.close();
	}

} // end class PokerGameTest