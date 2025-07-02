class Error {
    final float pi = 3.14f;

    final public void add() {
        // pi++; // Not allowed: trying to change final variable
    }
}

// Uncommenting this will cause error:
// class Error2 extends Error {
//     public void add() {
//         super.add();
//         --pi; // Error: pi is final
//     }
// }

class Exp8P2 {
    public static void main(String args[]) {
        // Error2 e2 = new Error2(); // Uncommenting will cause compile-time error
    }
}
