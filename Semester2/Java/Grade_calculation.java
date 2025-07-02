import java.util.*;

class Exp1P5 {
    public static void main(String args[]) {
        int a;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter marks");
        a = sc.nextInt();

        if ((a <= 100) && (a >= 90)) System.out.println("O");
        else if ((a < 90) && (a >= 80)) System.out.println("A+");
        else if ((a < 80) && (a >= 70)) System.out.println("A");
        else if ((a < 70) && (a >= 60)) System.out.println("B+");
        else if ((a < 60) && (a >= 55)) System.out.println("B");
        else if ((a < 55) && (a >= 50)) System.out.println("C+");
        else if ((a < 50) && (a >= 45)) System.out.println("C");
        else if ((a < 45) && (a >= 40)) System.out.println("D");
        else if (a < 40) System.out.println("F");
        else System.out.println("Not valid");
    }
}

// Switch-case version
import java.util.*;

class Switch {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int marks;

        System.out.println("Enter marks");
        marks = sc.nextInt();

        switch (marks / 10) {
            case 10:
            case 9: System.out.println("O"); break;
            case 8: System.out.println("A+"); break;
            case 7: System.out.println("A"); break;
            case 6: System.out.println("B+"); break;
            case 5: System.out.println("B"); break;
            case 4: System.out.println("C"); break;
            default: System.out.println("Fail");
        }
    }
}
