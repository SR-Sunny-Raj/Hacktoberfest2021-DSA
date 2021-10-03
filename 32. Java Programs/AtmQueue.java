/*
Due to the demonetization move, there is a long queue of people in front of ATMs. Due to withdrawal limit per person per day, people come in groups to withdraw money. Groups come one by one and line up behind the already present queue. The groups have a strange way of arranging themselves. In a particular group, the group members arrange themselves in increasing order of their height(not necessarily strictly increasing).
Swapy observes a long queue standing in front of the ATM near his house. Being a curious kid, he wants to count the total number of groups present in the queue waiting to withdraw money. Since groups are standing behind each other, one cannot differentiate between different groups and the exact count cannot be given. Can you tell him the minimum number of groups that can be observed in the queue?

input

4
1 2 3 4

output

1
*/
import java.util.*;
class AtmQueue {
    public static void main(String args[] ) throws Exception {
    
    Scanner s=new Scanner(System.in);
    int n=s.nextInt();
    int count=1;
    int[] a=new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=s.nextInt();
    }
            int min=a[0];
    for(int i=0;i<n-1;i++)
    {
        {
            if(a[i]-a[i+1]>0)
            {
            count++;      
            }
        }
    }
    System.out.println(count);
    }
}
