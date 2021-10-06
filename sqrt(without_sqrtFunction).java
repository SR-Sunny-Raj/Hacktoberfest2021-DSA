import java.util.*;

class sqrtwithoutmethod {
    public static void main(String args[]) {
        int a;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter a number to find its square root without inbuild sqrt function");
        a = sc.nextInt();
        float c = sqrt(a);
        System.out.println("the square root of the given number is=" + c);
    }

    public static float sqrt(int a) {
        float t, s = a / 2;
        do {
            t = s;
            s = (t + (a / t)) / 2;
        } while ((t - s) != 0);
        return s;
    }
}
