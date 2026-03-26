package ntou.cs.java2026;

public class PokerGame {

	private DeckOfCards myDeckOfCards;

	public PokerGame() {
		myDeckOfCards = new DeckOfCards();
		myDeckOfCards.shuffle();
	}

	public PokerGame(PokerGame game) {
		myDeckOfCards = game.myDeckOfCards;
		myDeckOfCards.reset();
	}

	public DeckOfCards getMyDeckOfCards() {
		return this.myDeckOfCards;
	}

	public void dealFiveCards() {
		int totalPoints = 0;

		try {
			for (int i = 0; i < 5; i++) {
				Card currentCard = myDeckOfCards.dealCard();
				int points = currentCard.getPoints();
				totalPoints += points;
				System.out.println("You got " + currentCard + ", " + points + " points.");
			}
			System.out.println("Your total points are " + totalPoints + ".");
			System.out.println();
		} catch (NullPointerException e) {
			System.out.println("No card can be dealt, please restart the game!");
			System.out.println();
		}
	}

} // end class PokerGame