class Ticket extends Thread {
    private int avail = 1;

    public synchronized void run() {
        if (avail > 0) {
            System.out.println("Ticket booked");
            avail--;
        } else {
            System.out.println("Ticket not booked");
        }
    }
}

class Exp11P4 {
    public static void main(String args[]) {
        Ticket t = new Ticket();

        Thread jay = new Thread(t);
        jay.start();

        Thread jenil = new Thread(t);
        jenil.start();
    }
}
