//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int val = 1, space = num / 2, count = 1;

        for (int i = 1; i <= num; i++) {

            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }

            int op = val;
            for (int j = 1; j <= count; j++) {
                System.out.print(op + "\t");

                if (j <= count / 2) {
                    op++;
                } else {
                    op--;
                }
            }

            if (i <= num / 2) {
                space--;
                val++;
                count += 2;
            } else {
                space++;
                val--;
                count -= 2;
            }
            System.out.println();
        }
    }
}
