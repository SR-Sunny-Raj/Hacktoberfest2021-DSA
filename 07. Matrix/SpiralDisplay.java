// https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/spiral-display-official/ojquestion

import java.util.Scanner;

public class SpiralDisplay {
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

        int rMin = 0, cMin = 0, rMax = n - 1, cMax = m - 1, counter = 0;
        while (counter < n * m) {
            //left boundary
            for (int row = rMin; row <= rMax && counter < n * m; row++) {
                System.out.println(arr[row][cMin]);
                counter++;
            }
            cMin++;

            //bottom boundary
            for (int col = cMin; col <= cMax && counter < n * m; col++) {
                System.out.println(arr[rMax][col]);
                counter++;
            }
            rMax--;

            //right boundary
            for (int row = rMax; row >= rMin && counter < n * m; row--) {
                System.out.println(arr[row][cMax]);
                counter++;
            }
            cMax--;

            //top boundary
            for (int col = cMax; col >= cMin && counter < n * m; col--) {
                System.out.println(arr[rMin][col]);
                counter++;
            }
            rMin++;

        }
        // completed

    }
}
