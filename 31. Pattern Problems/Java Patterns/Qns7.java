// Question No: 7

package com.java;

public class Qns7 {
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }

    static void Answer(int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if(col >= row){
                    System.out.print("*");
                }
                else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}

// output:
// *****
//  ****
//   ***
//    **
//     *
