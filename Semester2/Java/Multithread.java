class Table extends Thread {
    private int n;

    public Table(int a) {
        n = a;
    }

    public void run() {
        System.out.println("Table of " + n + " is:");
        for (int i = 1; i <= 10; i++) {
            System.out.println(n + " * " + i + " = " + (n * i));
        }
    }
}

class Cal {
    public static void main(String[] args) {
        Table t5 = new Table(5);
        Table t7 = new Table(7);
        Table t11 = new Table(11);

        Thread a = new Thread(t5);
        Thread b = new Thread(t7);
        Thread c = new Thread(t11);

        a.start();
        try { a.join(); } catch (Exception e) {}

        b.start();
        try { b.join(); } catch (Exception e) {}

        c.start();
    }
}
