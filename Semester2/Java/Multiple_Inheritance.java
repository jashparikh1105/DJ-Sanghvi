import java.util.*;

class Student {
    protected int rollno;
    public void read() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roll no of Student");
        rollno = sc.nextInt();
    }
}

class Test extends Student {
    protected int sem1_marks, sem2_marks;
    public void read() {
        super.read();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter marks for both sems");
        sem1_marks = sc.nextInt();
        sem2_marks = sc.nextInt();
    }
}

interface Sports {
    int itnl = 100, nat = 75, state = 50;
    void score();
}

class Result extends Test implements Sports {
    private int total;

    public void score() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter sports level:\n1) International\n2) National\n3) State");
        int n = sc.nextInt();

        if (n == 1)
            total = sem1_marks + itnl + sem2_marks;
        else if (n == 2)
            total = sem1_marks + nat + sem2_marks;
        else if (n == 3)
            total = sem1_marks + state + sem2_marks;
        else {
            System.out.println("Invalid choice. No participation in sports.");
            total = sem1_marks + sem2_marks;
        }

        System.out.println("Roll No: " + rollno);
        System.out.println("Sem 1 Marks: " + sem1_marks);
        System.out.println("Sem 2 Marks: " + sem2_marks);
        System.out.println("Total: " + total);
    }
}

class Exp8P1 {
    public static void main(String args[]) {
        Result r = new Result();
        r.read();
        r.score();
    }
}
