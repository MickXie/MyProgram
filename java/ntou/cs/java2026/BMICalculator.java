package ntou.cs.java2026;

import java.util.Scanner;

public class BMICalculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Welcome to the BMI (Body Mass Index) calculator");
        System.out.print("Please enter your weight (kilograms): ");
        double weightKg = input.nextDouble();
        System.out.print("Please enter your height (centimeters): ");
        double heightCm = input.nextDouble();
        if (weightKg <= 0 || heightCm <= 0) {
            System.out.println("Invalid input. Weight and height must be positive.");
            input.close();
            return;
        }
        double heightM = heightCm / 100.0;
        double bmi = weightKg / (heightM * heightM);
        double bmiRounded = Math.round(bmi * 10.0) / 10.0;
        String category;
        if (bmiRounded < 18.5) {
            category = "Underweight";
        } else if (bmiRounded < 25.0) {
            category = "Normal";
        } else if (bmiRounded < 30.0) {
            category = "Overweight";
        } else {
            category = "Obese";
        }
        System.out.println("Your BMI is " + String.format("%.1f", bmiRounded) + " (" + category + ")");
        input.close();
        
    }
}