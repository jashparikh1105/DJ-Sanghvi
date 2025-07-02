import java.util.Scanner;

class Exp3P1 {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a sentence");
        String s = sc.nextLine();

        int u = 0, l = 0, space = 0, n = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (Character.isUpperCase(ch))
                u++;
            if (Character.isLowerCase(ch))
                l++;
            if (Character.isWhitespace(ch))
                space++;
            if (Character.isDigit(ch))
                n++;
        }

        System.out.println("Uppercase are " + u);
        System.out.println("Lowercase are " + l);
        System.out.println("Spaces are " + space);
        System.out.println("Numbers are " + n);
    }
}
