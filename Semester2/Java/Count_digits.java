class Exp1P3 {
    public static void main(String args[]) {
        long a, r;
        int n = 0;

        a = Long.parseLong(args[0]);

        while (a != 0) {
            r = a % 10;
            n++;
            a = a / 10;
        }

        System.out.println("Total number of digits is " + n);
    }
}
