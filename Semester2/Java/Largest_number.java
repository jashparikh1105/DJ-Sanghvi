import java.util.*;

class Exp1_P1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, max;

        System.out.println("Enter three numbers");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        if ((a > b) && (a > c))
            System.out.println("The largest number is " + a);
        if ((b > a) && (b > c))
            System.out.println("The largest number is " + b);
        if ((c > a) && (c > b))
            System.out.println("The largest number is " + c);

        max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
        System.out.println("The greatest number is " + max);
    }
}
