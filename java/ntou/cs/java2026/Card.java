package ntou.cs.java2026;

public class Card {

	private final String face; // face of card ("Ace", "Deuce", ...)
	private final String suit; // suit of card ("Hearts", "Diamonds", ...)

	// two-argument constructor initializes card's face and suit
	public Card(String face, String suit) {
		this.face = face;
		this.suit = suit;
	}

	// return String representation of Card
	public String toString() {
		return face + " of " + suit;
	}

	public int getPoints() {
		if (face.equals(DeckOfCards.FACES[0])) {
			return 20; // Ace
		} else if (face.equals(DeckOfCards.FACES[1])) {
			return 2; // Deuce
		} else if (face.equals(DeckOfCards.FACES[2])) {
			return 3; // Three
		} else if (face.equals(DeckOfCards.FACES[3])) {
			return 4; // Four
		} else if (face.equals(DeckOfCards.FACES[4])) {
			return 5; // Five
		} else if (face.equals(DeckOfCards.FACES[5])) {
			return 6; // Six
		} else if (face.equals(DeckOfCards.FACES[6])) {
			return 7; // Seven
		} else if (face.equals(DeckOfCards.FACES[7])) {
			return 8; // Eight
		} else if (face.equals(DeckOfCards.FACES[8])) {
			return 9; // Nine
		} else if (face.equals(DeckOfCards.FACES[9])) {
			return 10; // Ten
		} else if (face.equals(DeckOfCards.FACES[10])) {
			return 11; // Jack
		} else if (face.equals(DeckOfCards.FACES[11])) {
			return 12; // Queen
		} else {
			return 13; // King
		}
	}

} // end class Card