import java.util.*;

class Staff {
    protected int code;
    protected String name;
}

class Teacher extends Staff {
    protected String sub;
    protected int exp;

    public void read() {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter Name, Code, Subject and years of experience of Teacher respectively");
        name = ob.nextLine();
        code = ob.nextInt();
        ob.nextLine(); // flush
        sub = ob.nextLine();
        exp = ob.nextInt();
    }

    public void display() {
        System.out.println("Teacher details:");
        System.out.println("NAME: " + name + "\nCODE: " + code + "\nSUBJECT: " + sub + "\nEXPERIENCE: " + exp);
    }
}

class Typist extends Staff {
    protected int exp, speed;

    public void read() {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter Name, Code, Speed and years of experience of Typist respectively");
        name = ob.nextLine();
        code = ob.nextInt();
        speed = ob.nextInt();
        exp = ob.nextInt();
    }

    public void display() {
        System.out.println("Typist details:");
        System.out.println("NAME: " + name + "\nCODE: " + code + "\nSPEED: " + speed + "\nEXPERIENCE: " + exp);
    }
}

class Officer extends Staff {
    protected String dept, grade;

    public void read() {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter Name, Code, Department and Grade of Officer respectively");
        name = ob.nextLine();
        code = ob.nextInt();
        ob.nextLine(); // flush
        dept = ob.nextLine();
        grade = ob.nextLine();
    }

    public void display() {
        System.out.println("Officer details:");
        System.out.println("NAME: " + name + "\nCODE: " + code + "\nDEPARTMENT: " + dept + "\nGRADE: " + grade);
    }
}

class Regular extends Typist {
    protected int sal;

    public void read() {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter Salary");
        sal = ob.nextInt();
    }

    public void display() {
        System.out.println("SALARY: " + sal);
    }
}

class Casual extends Typist {
    protected int daily_wages;

    public void read() {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter Daily Wages");
        daily_wages = ob.nextInt();
    }

    public void display() {
        System.out.println("DAILY WAGES: " + daily_wages);
    }
}

class Exp7P2 {
    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        int a, b;

        System.out.println("ENTER OPTION \n1 - TEACHER\n2 - TYPIST\n3 - OFFICER");
        a = ob.nextInt();

        switch (a) {
            case 1:
                Teacher t = new Teacher();
                t.read();
                t.display();
                break;

            case 2:
                System.out.println("ENTER OPTION \n1 - REGULAR\n2 - CASUAL");
                b = ob.nextInt();

                if (b == 1) {
                    Typist tt = new Typist();
                    tt.read();
                    tt.display();

                    Regular r = new Regular();
                    r.read();
                    r.display();
                }

                if (b == 2) {
                    Typist tt = new Typist();
                    tt.read();
                    tt.display();

                    Casual c = new Casual();
                    c.read();
                    c.display();
                }
                break;

            case 3:
                Officer o = new Officer();
                o.read();
                o.display();
                break;

            default:
                System.out.println("Invalid option");
        }
    }
}
