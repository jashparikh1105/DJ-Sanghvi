import java.util.*;

// Abstract base class
abstract class Shape {
    protected float r, l, b, h, area;

    abstract public void accept();
    abstract public void calculate();

    public void display() {
        System.out.println("Area is " + area);
    }
}

// Circle class
class Circle extends Shape {
    public void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter radius of circle");
        r = sc.nextFloat();
    }

    public void calculate() {
        area = 3.14f * r * r;
    }
}

// Rectangle class
class Rectangle extends Shape {
    public void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length and breadth of rectangle");
        l = sc.nextFloat();
        b = sc.nextFloat();
    }

    public void calculate() {
        area = l * b;
    }
}

// Triangle class
class Triangle extends Shape {
    public void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the base and height of triangle");
        b = sc.nextFloat();
        h = sc.nextFloat();
    }

    public void calculate() {
        area = 0.5f * b * h;
    }
}

// Main class
class Exp9P1 {
    public static void main(String args[]) {
        Circle c = new Circle();
        c.accept();
        c.calculate();
        c.display();

        Rectangle r = new Rectangle();
        r.accept();
        r.calculate();
        r.display();

        Triangle t = new Triangle();
        t.accept();
        t.calculate();
        t.display();
    }
}
