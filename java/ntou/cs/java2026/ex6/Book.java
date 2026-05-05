package ntou.cs.java2026.ex6;

public class Book extends Product {
    private final String author;

    public Book(String name, double price, String author) {
        super(name, price);
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    @Override
    public double calculateProductItemPrice() {
        return getPrice() * getQuantity() * 0.9;
    }

    @Override
    public String toString() {
        return super.toString() + " | Author: " + author;
    }
}
