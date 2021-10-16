package com.company;
import java.util.Arrays;
public class Matrix {
    
    //Problem:  Find the sum of of the diagonal elements of the matrix.
    
    public static void main(String[] args) {
        int [][] arr = {{1, 2, 3}, {4, 5, 6}, {8, 9, 0}};
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if(i == j)
                {
                    sum += arr[i][j];
                }
            }
        }
        System.out.println("Our Matrix is ");
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("The sum of the diagonal elements of an matrix is "+sum);
    }
}
