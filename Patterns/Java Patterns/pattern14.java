//Pepcoding
//https://www.pepcoding.com/resources/online-java-foundation/patterns

import java.util.*;

public class pattern14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for (int i = 1; i <= 10; i++) {
            System.out.println(num + " * " + i + " = " + (i * num));
        }
    }
}
