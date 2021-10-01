//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.Scanner;

public class pattern10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int os = num / 2;
        int is = -1;

        for (int i = 1; i <= num; i++) {

            for (int j = 1; j <= os; j++) {
                System.out.print("\t");
            }

            System.out.print("*\t");

            for (int j = 1; j <= is; j++) {
                System.out.print("\t");
            }

            if (i > 1 && i < num) {
                System.out.print("*\t");
            }

            if (i <= num / 2) {
                os--;
                is += 2;
            } else {
                os++;
                is -= 2;
            }
            System.out.println();
        }
    }
}
