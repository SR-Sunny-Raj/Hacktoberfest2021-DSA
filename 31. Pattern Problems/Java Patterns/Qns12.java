// Questio No: 12

package com.java;

public class Qns12 {
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }
    static void Answer(int n){
        for (int row = 0; row <= n; row++) {
            int col_no = row;
            int space = n - row;
            for (int s = 0; s < space; s++) {
                System.out.print(" ");
            }
            for (int col = 0; col < col_no; col++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}


// Output
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
