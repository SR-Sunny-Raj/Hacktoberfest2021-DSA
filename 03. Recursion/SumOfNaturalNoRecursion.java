import java.util.Scanner;
/**
 * SumOfNaturalNoRecursion
 */
public class SumOfNaturalNoRecursion {

    int sum = 0;

    int fun(int n)
    {
        if(n>0)
            return n + fun(n-1);
        else
            return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        SumOfNaturalNoRecursion s = new SumOfNaturalNoRecursion();
        System.out.println(s.fun(n));
    }
}