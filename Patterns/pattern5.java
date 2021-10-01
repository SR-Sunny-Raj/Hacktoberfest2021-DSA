//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.Scanner;

public class pattern5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int star = 1, space = n / 2;
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }

            for (int j = 1; j <= star; j++) {
                System.out.print("*\t");
            }

            if (i <= n / 2) {
                star += 2;
                space--;
            } else {
                space++;
                star -= 2;
            }
            System.out.println();
        }
    }
}