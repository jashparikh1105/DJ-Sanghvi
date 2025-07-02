import java.util.Vector;

class Exp4P1 {
    public static void main(String args[]) {
        Vector v = new Vector();

        for (int i = 0; i < args.length; i++) {
            v.addElement(args[i]);
        }

        System.out.println("The names entered are:");
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.elementAt(i));
        }
    }
}
