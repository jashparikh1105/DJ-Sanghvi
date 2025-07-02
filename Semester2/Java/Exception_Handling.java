import java.io.*;

class Construct {
    public static void main(String[] args) throws IOException {
        int a, b;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter 2 Numbers");
        try {
            a = Integer.parseInt(br.readLine());
            b = Integer.parseInt(br.readLine());
            System.out.println("Result: " + (a / b));
        } catch (ArithmeticException ae) {
            System.out.println("Cannot divide by zero");
        } catch (NumberFormatException nfe) {
            System.out.println("Please enter numbers only");
        }

        int c[] = new int[5];
        try {
            for (int i = 0; i <= 5; i++) {  // Intentional out-of-bounds
                System.out.println("Enter element:");
                c[i] = Integer.parseInt(br.readLine());
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Please enter lesser elements");
        }
    }
}
