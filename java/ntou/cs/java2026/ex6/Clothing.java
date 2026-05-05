package ntou.cs.java2026.ex6;

public class Clothing extends Product {
    private final String size;

    public Clothing(String name, double price, String size) {
        super(name, price);
        this.size = size;
    }

    public String getSize() {
        return size;
    }

    @Override
    public double calculateProductItemPrice() {
        return getPrice() * getQuantity();
    }

    @Override
    public String toString() {
        return super.toString() + " | Size: " + size;
    }
}
