//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int count = 1, space = (num * 2) - 3;

        for (int i = 1; i <= num; i++) {
            int val = 1;
            for (int j = 1; j <= count; j++) {
                // int val
                System.out.print(val + "\t");
                val++;
            }
            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }

            if (i == num) {
                count--;
                val--;
            }

            val--;
            int op2 = val;
            for (int j = 1; j <= count; j++) {
                System.out.print(op2 + "\t");
                op2--;
            }
            count++;
            space -= 2;
            val++;
            System.out.println();
        }
    }
}
