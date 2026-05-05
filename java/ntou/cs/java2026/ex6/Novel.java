package ntou.cs.java2026.ex6;

public class Novel extends Book {
    private final String genre;

    public Novel(String name, double price, String author, String genre) {
        super(name, price, author);
        this.genre = genre;
    }

    public String getGenre() {
        return genre;
    }

    @Override
    public String toString() {
        return super.toString() + " | Genre: " + genre;
    }
}
