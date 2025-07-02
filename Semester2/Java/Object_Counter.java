import java.util.*;

class Objects {
    private static int c;

    public Objects() {
        c++;
    }

    public static void display() {
        System.out.println(c);
    }
}

class Display {
    public static void main(String args[]) {
        Objects ob1 = new Objects();
        Objects ob2 = new Objects();
        Objects.display(); // prints 2

        Objects ob3 = new Objects();
        Objects ob4 = new Objects();
        Objects ob5 = new Objects();
        Objects ob6 = new Objects();
        Objects.display(); // prints 6
    }
}
