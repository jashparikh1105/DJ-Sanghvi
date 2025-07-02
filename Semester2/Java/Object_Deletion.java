class Delete {
    private static int count;

    public Delete() {
        count++;
    }

    public static void display() {
        System.out.println("Count: " + count);
    }

    protected void finalize() {
        System.out.println("Object is deleted");
    }
}

class Ex8P4 {
    public static void main(String args[]) {
        Delete D1 = new Delete();
        Delete D2 = new Delete();
        Delete D3 = new Delete();
        Delete D4 = new Delete();
        Delete D5 = new Delete();

        Delete.display();

        D1 = null;
        D3 = null;

        System.gc(); // Requests garbage collection
    }
}
