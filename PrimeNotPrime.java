import java.util.Scanner;
public class PrimeNotPrime
{
    public PrimeNotPrime()
    {
        Scanner input = new Scanner(System.in);
        int a=0;
        for(int j =0;j<10;j++){
        System.out.println("Enter any number to check for Prime");
        a=input.nextInt();
        
        for (int i=2;i<a;i++)
        {
            if (a%i==0)
            {
                System.out.println("Divided by "+i+". Not Prime");
                System.exit(0);
            }
        }
        System.out.println("This is a Prime Number");}
    }
}
            