import java.util.*;
 public class TowerTest 
 {
     public static void main (String[] args) {
         Scanner sc=new Scanner(System.in);
         
         System.out.println("Enter the number of disks :");
         int n=sc.nextInt();
         if(n>0 && n<=6)
         {  System.out.println("The sequence of moves involved in the Tower of Hanoi are:");
            towerOfHanoi(n, 'A', 'C', 'B');
         }
         else
         {
             System.out.println("Invalid input");
         }
     }
     
     static void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
        {
            if(n==1)
            {
                System.out.println("Move disk 1 from peg "+ from_rod + " to peg " + to_rod);
                return;
            }
            towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
            System.out.println("Move disk "+n+" from peg "+ from_rod + " to peg "+to_rod);
            towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
        }
 }
