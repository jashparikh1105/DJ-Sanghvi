import java.util.*;

class Exp1P4 {
    public static void main(String args[]) {
        int a, b, d;
        char c, n;

        do {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter two numbers");
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println("Enter an operator");
            sc.nextLine(); // consume newline
            c = sc.nextLine().charAt(0);

            switch (c) {
                case '+': d = a + b; System.out.println("Addition is " + d); break;
                case '-': d = a - b; System.out.println("Subtraction is " + d); break;
                case '/': d = a / b; System.out.println("Division is " + d); break;
                case '*': d = a * b; System.out.println("Multiplication is " + d); break;
                case '%': d = a % b; System.out.println("Modulus is " + d); break;
                default: System.out.println("Invalid operator");
            }

            System.out.println("Do you wish to do another operation? (y=yes/n=no)");
            n = sc.nextLine().charAt(0);
        } while (n == 'y' || n == 'Y');
    }
}
