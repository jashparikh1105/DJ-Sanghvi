import java.util.*;

class Base {
    protected double r;

    public Base(double radius) {
        r = radius;
    }
}

class Sub1 extends Base {
    protected double area;

    public Sub1(double radius) {
        super(radius);
    }

    public void area() {
        area = 3.142 * r * r;
        System.out.println("Area = " + area);
    }
}

class Sub2 extends Sub1 {
    protected double vol;

    public Sub2(double radius) {
        super(radius);
    }

    public void vol() {
        vol = (4f / 3) * (area * r);
        System.out.println("Volume = " + vol);
    }
}

class Exp7P1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter radius");
        double radius = sc.nextDouble();
        Sub2 s = new Sub2(radius);
        s.area();
        s.vol();
    }
}
