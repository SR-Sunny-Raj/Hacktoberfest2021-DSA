// Question No: 4

package com.java;

public class Qns4 {
    public static void main(String[] args) {
        int n = 6;
        Ans(n);
    }
    static void Ans(int n){
        for (int row = 0; row < n; row++) {
            for (int col = 0; col <= row; col++) {
                System.out.print(col + 1);
            }
            System.out.println();
        }
    }
}

// Output:
// 1
// 12
// 123
// 1234
// 12345
// 123456
