import java.util.*;

class Exp1_P6 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        float sum = 0;
        int i, n;

        System.out.println("Enter a number");
        n = sc.nextInt();

        for (i = 1; i <= n; i++) {
            sum = sum + (float)(1.0 / (i * i));
        }

        System.out.println("The sum is " + sum);
    }
}
