//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern17 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int space = num / 2, count = 1;
        for (int i = 1; i <= num; i++) {

            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }

            for (int j = 1; j <= count; j++) {
                System.out.print("*\t");
            }

            if (i < num / 2) {
                count++;
            } else if (i > num / 2) {
                if (i == (num / 2) + 1) {
                    space = num / 2;
                    count = num / 2;
                } else {
                    count--;
                }

            } else {
                space = 0;
                count = num;
            }

            System.out.println();
        }
    }
}
