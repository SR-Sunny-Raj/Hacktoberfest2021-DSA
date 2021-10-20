// Question No: 9

package com.java;

public class Qns9 {
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }

    static void Answer(int n){
        for (int row = 0; row < n; row++) {
            for (int col = 1; col <= 9; col++){
              //9 = 5th Odd Number
                if(col <= (9 - row) && col >= (1 + row)){
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
// *********
//  ******* 
//   *****  
//    ***   
//     *    
