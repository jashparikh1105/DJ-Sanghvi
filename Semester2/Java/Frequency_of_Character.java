import java.util.Scanner;

class Exp3P2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string");
        String s = sc.nextLine();

        System.out.println("Enter a character to search its occurrence");
        char a = sc.next().charAt(0);

        int c = 0;
        char b[] = s.toCharArray();

        for (int i = 0; i < b.length; i++) {
            if (Character.compare(a, b[i]) == 0)
                c++;
        }

        System.out.println("The letter " + a + " occurs " + c + " times");
    }
}
