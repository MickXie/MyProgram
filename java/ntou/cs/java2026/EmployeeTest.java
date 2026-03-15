package ntou.cs.java2026;

public class EmployeeTest {
        public static void main(String[] args) {
                Employee emp1 = new Employee("Bob", "Jones", 2875.00);
                Employee emp2 = new Employee("Susan", "Baker", 3150.75);

                System.out.printf("Employee 1: %s %s; Yearly Salary: %.2f%n",
                                emp1.getFirstName(), emp1.getLastName(), emp1.getYearlySalary());
                System.out.printf("Employee 2: %s %s; Yearly Salary: %.2f%n",
                                emp2.getFirstName(), emp2.getLastName(), emp2.getYearlySalary());

                System.out.println("Increasing employee salaries by 10%");

                emp1.setMonthlySalary(emp1.getMonthlySalary() * 1.10);
                emp2.setMonthlySalary(emp2.getMonthlySalary() * 1.10);

                System.out.printf("Employee 1: %s %s; Yearly Salary: %.2f%n",
                                emp1.getFirstName(), emp1.getLastName(), emp1.getYearlySalary());
                System.out.printf("Employee 2: %s %s; Yearly Salary: %.2f%n",
                                emp2.getFirstName(), emp2.getLastName(), emp2.getYearlySalary());
        }
}