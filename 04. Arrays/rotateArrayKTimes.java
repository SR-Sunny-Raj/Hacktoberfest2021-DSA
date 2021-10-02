// rotate an array by k times

import java.util.Scanner;

public class Question41 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = scn.nextInt();
        }

        // rotating array k times
        int k = scn.nextInt();
        k = k % a.length;
        if (k < 0) {
            k = k + a.length;
            k = k % a.length;
        }

        int[] ans1 = reverse(a, 0, a.length - 1);
        ans1 = reverse(ans1, 0, k - 1);
        ans1 = reverse(ans1, k, a.length - 1);

        for (int i = 0; i < ans1.length; i++) {
            System.out.print(ans1[i]);
            System.out.print(" ");
        }

    }

    public static int[] reverse(int[] a, int left, int right) {

        while (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
        return a;
    }
}
