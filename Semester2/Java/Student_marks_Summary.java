import java.util.Scanner;

class Exp2P2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students");
        int n = sc.nextInt();
        int max = 0;
        int i, j;

        int a[][] = new int[n][5];

        System.out.println("Enter roll number and marks of a student in 3 subjects");
        for (i = 0; i < n; i++) {
            for (j = 0; j < 4; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        for (i = 0; i < n; i++) {
            a[i][4] = a[i][1] + a[i][2] + a[i][3];
        }

        System.out.println("Roll No.\tSubject 1\tSubject 2\tSubject 3\tTotal");
        for (i = 0; i < n; i++) {
            System.out.println(a[i][0] + "\t\t" + a[i][1] + "\t\t" + a[i][2] + "\t\t" + a[i][3] + "\t\t" + a[i][4]);
        }

        for (i = 0; i < n; i++) {
            if (a[i][4] > a[max][4])
                max = i;
        }

        System.out.println("Student with maximum marks is Roll No. " + a[max][0] + " Marks are " + a[max][4]);
    }
}
