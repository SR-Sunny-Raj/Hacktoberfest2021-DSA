//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern19 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= num; j++) {

                if (i == 1) {
                    if (j <= (num / 2) + 1 || j == num) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else if (i <= num / 2) {
                    if (j == (num / 2) + 1 || j == num) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else if (i == (num / 2) + 1) {
                    System.out.print("*\t");
                } else if (i < num) {
                    if (j == (num / 2) + 1 || j == 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                } else {
                    if (j >= (num / 2) + 1 || j == 1) {
                        System.out.print("*\t");
                    } else {
                        System.out.print("\t");
                    }
                }

            }
            System.out.println();
        }
    }
}
