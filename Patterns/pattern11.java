//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int num = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    System.out.print(num + "\t");
                    num++;
                } else {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }
    }
}
