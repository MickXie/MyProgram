package ntou.cs.java2026.ex6;

import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {
    private List<Product> items;

    public ShoppingCart() {
        items = new ArrayList<>();
    }

    public void addItem(Product product, int quantity) {
        product.setQuantity(quantity);
        items.add(product);
        System.out.printf("Add %s | Subtotal: %.2f%n", product.toString(), product.calculateProductItemPrice());
    }

    public double calculateTotalPrice() {
        double total = 0;
        for (Product p : items) {
            total += p.calculateProductItemPrice();
        }
        return total;
    }

    public double applyDiscount(double discountPercentage) {
        return calculateTotalPrice() * (1 - discountPercentage / 100);
    }
}
