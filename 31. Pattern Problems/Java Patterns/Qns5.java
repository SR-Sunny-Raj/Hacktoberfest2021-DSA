// Question no: 5

package com.java;

public class Qns5 {
    public static void main(String[] args) {
        int n = 5;
        Ans(n);
    }

    static void Ans(int n){
        for (int row = 1; row <= n ; row++) {
            if(row <= 3){
                for (int i = 1; i <= row ; i++) {
                    System.out.print("*");
                }
            }
            else{
                for (int i = row; i <= 5; i++) {
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }
}

// Output
// *
// **
// ***
// **
// *
