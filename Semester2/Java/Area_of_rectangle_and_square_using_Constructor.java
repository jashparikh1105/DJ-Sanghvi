import java.util.*;

class Area {
    private float side, length, breadth, area;

    // Default Constructor - Square
    public Area() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the side of square:");
        side = sc.nextFloat();
        area = side * side;
        System.out.println("The area of square is: " + area);
    }

    // Parameterized Constructor - Rectangle
    public Area(float l, float b) {
        length = l;
        breadth = b;
        area = length * breadth;
        System.out.println("The area of rectangle is: " + area);
    }

    // Copy Constructor - Modified dimensions
    public Area(Area a) {
        length = a.length + 1;
        breadth = a.breadth - 1;
        area = length * breadth;
        System.out.println("The area of rectangle 2 is: " + area);
    }
}

class Exp6PB {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        Area s = new Area(); // Square via default constructor

        System.out.println("Enter the length and breadth of rectangle:");
        float l = sc.nextFloat();
        float b = sc.nextFloat();

        Area r = new Area(l, b); // Rectangle via parameterized constructor
        Area r1 = new Area(r);   // Rectangle 2 via copy constructor
    }
}
