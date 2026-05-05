package ntou.cs.java2026.ex6;

public class Shirt extends Clothing {
    private final String material;

    public Shirt(String name, double price, String size, String material) {
        super(name, price, size);
        this.material = material;
    }

    public String getMaterial() {
        return material;
    }

    @Override
    public String toString() {
        return super.toString() + " | Material: " + material;
    }
}
