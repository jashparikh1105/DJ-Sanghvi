import java.util.Scanner;

class Exp2P1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of array");
        int n = sc.nextInt();
        int a[] = new int[n];
        int s = 0, i;

        System.out.println("Enter the array elements");
        for (i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println("The array elements are");
        for (i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();

        for (i = 0; i < n; i++) {
            s = s + a[i];
        }

        for (i = 0; i < n; i++) {
            System.out.print((s - a[i]) + " ");
        }
    }
}
