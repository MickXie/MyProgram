package ntou.cs.java2026;

public class ComplexNumberCalculator {
    public static Complex calculate(Complex[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            throw new IllegalArgumentException("Input matrix cannot be null or empty");
        }
        for (Complex[] row : matrix) {
            if (row == null || row.length == 0) {
                throw new IllegalArgumentException("Input matrix cannot contain null or empty rows");
            }
        }

        Complex[] rowSums = new Complex[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            Complex sum = new Complex(0, 0);
            for (Complex num : matrix[i]) {
                sum = sum.add(num);
            }
            rowSums[i] = sum;
        }

        Complex result = new Complex(1, 0);
        for (Complex sum : rowSums) {
            result = result.multiply(sum);
        }

        return result;
    }
}