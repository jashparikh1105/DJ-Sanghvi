import java.util.*;

class Complex {
    private float img, real;

    public Complex() {}

    public Complex(float x, float y) {
        real = x;
        img = y;
    }

    public Complex add(Complex a) {
        Complex b = new Complex();
        b.real = real + a.real;
        b.img = img + a.img;
        return b;
    }

    public Complex sub(Complex c) {
        Complex d = new Complex();
        d.real = real - c.real;
        d.img = img - c.img;
        return d;
    }

    public void display() {
        if (img >= 0)
            System.out.println("Complex Number: " + real + "+" + img + "i");
        else
            System.out.println("Complex Number: " + real + img + "i");
    }
}

class Exp5P3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter real and imaginary part of complex number");
        float x = sc.nextFloat();
        float y = sc.nextFloat();
        Complex C1 = new Complex(x, y);
        C1.display();

        System.out.println("Enter real and imaginary part of complex number");
        x = sc.nextFloat();
        y = sc.nextFloat();
        Complex C2 = new Complex(x, y);
        Complex C3 = new Complex();

        C3 = C1.add(C2);
        System.out.println("The sum is ");
        C3.display();

        C3 = C1.sub(C2);
        System.out.println("The Subtraction is ");
        C3.display();
    }
}
