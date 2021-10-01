//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.Scanner;

public class pattern6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int star = (num / 2) + 1, space = 1;

        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= star; j++) {
                System.out.print("*\t");
            }

            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }

            for (int j = 1; j <= star; j++) {
                System.out.print("*\t");
            }

            if (i <= num / 2) {
                star--;
                space += 2;
            } else {
                star++;
                space -= 2;
            }
            System.out.println();
        }
    }
}
