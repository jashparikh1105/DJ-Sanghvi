import java.util.Scanner;

class Exp5P2 {
    static int area(int l, int b) {
        return l * b;
    }

    static int area(int s) {
        return s * s;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Area to be found of \n1.Rectangle\n2.Square");
        int choice = sc.nextInt();

        if (choice == 1) {
            System.out.println("Enter the length and breadth of rectangle");
            int l = sc.nextInt();
            int b = sc.nextInt();
            System.out.println("Area of rectangle is " + area(l, b));
        } else if (choice == 2) {
            System.out.println("Enter the side of square");
            int s = sc.nextInt();
            System.out.println("Area of Square is " + area(s));
        } else {
            System.out.println("Invalid Input");
        }
    }
}
