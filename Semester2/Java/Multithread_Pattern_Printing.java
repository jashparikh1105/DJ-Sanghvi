class Slash extends Thread {
    public void run() {
        for (int i = 0; i <= 8; i++) {
            System.out.print("/");
            try { Thread.sleep(10); } catch (InterruptedException ie) {}
        }
    }
}

class Star extends Thread {
    public void run() {
        for (int i = 0; i <= 8; i++) {
            System.out.print("*");
            try { Thread.sleep(10); } catch (InterruptedException ie) {}
        }
    }
}

class Exp11P2 {
    public static void main(String args[]) {
        Slash sh = new Slash();
        Thread t = new Thread(sh);
        t.start();

        Star st = new Star();
        Thread t1 = new Thread(st);
        t1.start();
    }
}
