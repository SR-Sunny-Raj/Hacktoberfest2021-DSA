//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int star = num, osp = 0, isp = num - 4;

        for (int i = 1; i <= num; i++) {

            for (int j = 1; j <= osp; j++) {
                System.out.print("\t");
            }

            for (int j = 1; j <= star; j++) {
                if (i > 1 && i <= num / 2 && j > 1 && j < star)
                    System.out.print("\t");
                else
                    System.out.print("*\t");
            }

            if (i <= num / 2) {
                osp++;
                star -= 2;
            } else {
                osp--;
                star += 2;
            }
            System.out.println();
        }
    }
}
