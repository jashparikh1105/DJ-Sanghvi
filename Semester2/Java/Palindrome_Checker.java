import java.util.Scanner;

class Exp3P3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string to check if it's a palindrome");
        String s = sc.nextLine();

        StringBuffer sb = new StringBuffer(s);
        sb.reverse();
        String s1 = sb.toString();

        if (s.compareToIgnoreCase(s1) == 0)
            System.out.println("Palindrome");
        else
            System.out.println("Not Palindrome");
    }
}
