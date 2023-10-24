// Question No: 6

package com.java;

public class Qns6 {
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }

    static void Answer(int n){
        for (int row = 1; row <= n ; row++) {
            for (int col = 1; col <= n ; col++) {
                if(col >= ((n + 1) - row)){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}

// Output
//     *
//    **
//   ***
//  ****
// *****
