// To print 2d array like: wave traversal
// row by row

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = scn.nextInt();
            }
        }

        for (int i = 0; i < arr.length; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < arr[0].length; j++) {
                    System.out.println(arr[i][j]);
                }
            } else {
                for (int j = arr[0].length - 1; j >= 0; j--) {
                    System.out.println(arr[i][j]);
                }
            }
        }
    }
}

// leetcode Question
