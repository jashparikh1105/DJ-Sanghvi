import java.util.Scanner;

class Exp2P3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number for rows");
        int n = sc.nextInt();

        int i, j;
        int a[][] = new int[n][];

        for (i = 0; i < n; i++) {
            a[i] = new int[i + 1];
            for (j = 0; j <= i; j++)
                a[i][j] = j + 1;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
    }
}
