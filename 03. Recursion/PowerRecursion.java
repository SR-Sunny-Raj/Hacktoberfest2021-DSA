import java.util.Scanner;
/**
 * SumOfNaturalNoRecursion
 */
public class PowerRecursion {

    int fun(int m,int n)
    {
        if(n != 0)
            return m * fun(m,n-1);
        else 
            return 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        sc.close();
        PowerRecursion s = new PowerRecursion();
        System.out.println(s.fun(m,n));
    }
}