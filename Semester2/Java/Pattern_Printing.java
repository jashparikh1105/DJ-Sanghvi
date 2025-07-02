import java.util.*;

class Exp1_P7 {
    public static void main(String args[]) {
        int i, j, n;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter rows");
        n = sc.nextInt();

        for (i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                for (j = 1; j <= i; j++)
                    System.out.print(j);
            } else {
                for (j = i; j >= 1; j--)
                    System.out.print(j);
            }
            System.out.println();
        }
    }
}
