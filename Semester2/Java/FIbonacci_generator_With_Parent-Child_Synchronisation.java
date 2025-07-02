import java.util.*;

class Fibonacci extends Thread {
    int n;
    int[] a;

    public void accept(int x) {
        n = x;
        a = new int[n];
    }

    public void run() {
        synchronized (a) {
            a[0] = 0;
            a[1] = 1;
            for (int i = 2; i < n; i++) {
                a[i] = a[i - 2] + a[i - 1];
            }

            try { Thread.sleep(100); } catch (Exception e) {}
            a.notify(); // notify waiting parent thread
        }
    }
}

class Input extends Thread {
    Fibonacci f;

    public Input(Fibonacci x) {
        Scanner sc = new Scanner(System.in);
        f = x;
        System.out.println("Enter a number");
        f.accept(sc.nextInt());
    }

    public void run() {
        synchronized (f.a) {
            try { f.a.wait(); } catch (Exception e) {}

            for (int i = 0; i < f.n; i++) {
                System.out.print(f.a[i] + " ");
            }
        }
    }
}

class Fibo {
    public static void main(String[] args) {
        Fibonacci f = new Fibonacci();
        Input i = new Input(f);

        Thread t = new Thread(f);
        Thread t1 = new Thread(i);

        t1.start();
        t.start();
    }
}
