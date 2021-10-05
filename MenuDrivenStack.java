// Program for stack implementation in java.
import java.util.*;
class STACK_IMPLEMENTATION
{
    int[] a;
    private int top=-1;
    private int size;
    STACK_IMPLEMENTATION(int s)
    {
        a=new int[s];
        size = s;
        System.out.println(size);
    }
    private boolean STACK_EMPTY()
    {
        if (top == -1)
        {
            System.out.println("!! STACK UNDERFLOW !!");
            return true;
        }
        else
            return false;
    }
    private boolean STACK_FULL()
    {
        if (top == size - 1)
        {
            System.out.println("!! STACK OVERFLOW !! ");
            return true;
        }
        else
            return false;
    }
    void PUSH(int val)
    {
        if (STACK_FULL())
            return;
        top=top+1;
        a[top] = val;
    }
    void POP()
    {
        if (STACK_EMPTY())
            return;
        System.out.println("POPED VALUE = "+a[top--]);
    }
    void SHOW()
    {
        System.out.print("STACK IS : ");
        for(int i=0;i<=top;i++)
            System.out.print(a[i]+" ");
        System.out.println();
    }
}
public class STACK
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int s;
        System.out.print("Enter size of stack : ");
        s = sc.nextInt();
        STACK_IMPLEMENTATION s1 =new STACK_IMPLEMENTATION(s);
        System.out.println("PRESS !!!\n1 : PUSH\n2 : POP ");
        System.out.print("Enter Choice : ");
        int choice =sc.nextInt();
        int value;
        while(choice==1||choice==2)
        {
            if(choice==1)
            {
                System.out.print("Enter Element to push : ");
                value=sc.nextInt();
                s1.PUSH(value);
            }
            else if(choice==2)
            {
                s1.POP();
            }
            else if(choice==3)
            {
                System.exit(0);
            }
            s1.SHOW();
            System.out.println("PRESS !!!\n1 : PUSH\n2 : POP\n3 : EXIT");
            System.out.print("Enter Choice : ");
            choice=sc.nextInt();
        }
    }
}
