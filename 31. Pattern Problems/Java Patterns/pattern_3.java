//Question no: 3


package com.java;

public class pattern_3{
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }

    static void Answer(int n) {
        for (int row = 0; row < n ; row++) {
            for (int col = 1; col <= (n - row) ; col++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}

// Output
// *****
// ****
// ***
// **
// *
