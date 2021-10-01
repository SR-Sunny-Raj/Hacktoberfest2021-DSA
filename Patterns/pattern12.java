//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i >= j) {
                    System.out.print(a + "\t");
                    int c = a + b;
                    a = b;
                    b = c;
                }
            }
            System.out.println();
        }
    }
}
