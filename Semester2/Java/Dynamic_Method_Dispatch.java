import java.util.*;

class Base {
    public void display() {
        System.out.println("Base class");
    }
}

class Child1 extends Base {
    public void display() {
        System.out.println("Child1 Class");
    }
}

class Exp8P3 {
    public static void main(String[] args) {
        Base ref;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter choice: 1) Base class  2) Child class");
        int a = sc.nextInt();

        if (a == 1) {
            ref = new Base();
        } else {
            ref = new Child1();
        }

        ref.display();  // Dynamic method dispatch
    }
}
