//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern13 {

    public static int fact(int n) {
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
        }
        return f;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for (int i = 0; i < num; i++) {
            for (int j = 0; j <= i; j++) {
                int n = fact(i);
                int r = fact(j);
                int q = fact(i - j);
                int nCr = n / (r * q);
                System.out.print(nCr + "\t");
            }
            System.out.println();
        }
    }
}
