//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.Scanner;

public class pattern8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int space = 0;
        for (int i = 1; i <= num; i++) {

            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }
            System.out.print("*");

            space++;

            System.out.println();
        }
    }
}
