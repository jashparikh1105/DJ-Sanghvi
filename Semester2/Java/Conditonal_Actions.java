import java.util.*;

class Exp1P1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a;

        System.out.println("Enter a number");
        a = sc.nextInt();

        if ((a % 2 == 0) && (a >= 2) && (a <= 5))
            System.out.println("Not Weird");
        if ((a % 2 == 0) && (a >= 6) && (a <= 20))
            System.out.println("Weird");
        if ((a % 2 == 0) && (a > 20))
            System.out.println("Not Weird");
        if ((a % 2 != 0))
            System.out.println("Weird");
    }
}
