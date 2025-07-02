import java.util.*;

class Exp5P1a {
    int power(int x, int y) {
        if (y == 0)
            return 1;
        else
            return x * power(x, y - 1);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter base number");
        int x = sc.nextInt();
        System.out.println("Enter power number");
        int y = sc.nextInt();

        Exp5P1a ob = new Exp5P1a();
        int ans = ob.power(x, y);
        System.out.println("The answer is " + ans);
    }
}
