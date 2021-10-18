// Question No: 8

package com.java;

public class Qns8 {
    public static void main(String[] args) {
        int n = 5;
        Answer(n);
    }

    static void Answer(int n){
        for (int row = 0; row < n; row++) {
            for (int col = 1; col <= 9; col++) {
                if(col >= (n - row) && col <= (n+ row)){
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


// Output:
//     *    
//    ***   
//   *****  
//  ******* 
// *********
