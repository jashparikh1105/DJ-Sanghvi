import java.util.*;

class Exp4P2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Vector v = new Vector();

        System.out.println("Enter number of strings");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        for (int i = 0; i < n; i++) {
            System.out.println("Enter a String:");
            String s = sc.nextLine();
            v.addElement(s);
        }

        System.out.println("Names Entered are:");
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.elementAt(i));
        }

        System.out.println("Enter another string");
        String s = sc.nextLine();
        int i = v.indexOf(s);

        if (i == -1)
            v.addElement(s);
        else
            v.removeElementAt(i);

        System.out.println("Final List is:");
        for (i = 0; i < v.size(); i++) {
            System.out.println(v.elementAt(i));
        }
    }
}
