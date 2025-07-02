import java.util.*;

class Student {
    private int id, p, c, m, total;
    private String name;

    public void get() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name, id, marks in Physics, Chemistry and Maths");
        name = sc.nextLine();
        id = sc.nextInt();
        p = sc.nextInt();
        c = sc.nextInt();
        m = sc.nextInt();
        total = p + c + m;
    }

    public boolean sort(Student s) {
        return total > s.total;
    }

    public void put() {
        System.out.println(name + "\t" + id + "\t" + p + "\t" + c + "\t" + m + "\t" + total);
    }
}

class test1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students");
        int n = sc.nextInt();
        Student temp;
        Student s1[] = new Student[n];

        for (int i = 0; i < n; i++) {
            s1[i] = new Student();
            s1[i].get();
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (s1[j].sort(s1[j + 1])) {
                    temp = s1[j];
                    s1[j] = s1[j + 1];
                    s1[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++)
            s1[i].put();
    }
}
