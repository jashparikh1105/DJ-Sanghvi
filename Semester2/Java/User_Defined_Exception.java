import java.util.*;

class MarksOutOfBoundsException extends Exception {
    public MarksOutOfBoundsException() {
        System.out.println("Please enter correct marks");
    }
}

class Exmarks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int marks;

        System.out.println("Enter marks:");
        marks = sc.nextInt();

        try {
            if (marks > 100 || marks < 0)
                throw new MarksOutOfBoundsException();
        } catch (MarksOutOfBoundsException e) {
            // Already handled in constructor
        }

        System.out.println("Marks are: " + marks);
    }
}
