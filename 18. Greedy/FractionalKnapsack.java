import java.util.*;

public class FractionalKnapsack{
//Knapsack Greedy / Fractional Knapsack    
    public static void knapsack(int n, int m, float[] w, float[] p) {
       float[] x = new float[n];
        int k;
        float u=m,profit=0,weight=0;
        for(int i=0;i<n;i++)
            x[i]=0;
        for(k = 0; k < n; k++) {
            if(w[k]>u)
                break;
            x[k]=1;
            u=u-w[k];
        }
        if(k<n)
            x[k]=u/w[k];
        System.out.println("Solution: ");
        for(int i=0;i<n;i++)
            System.out.println(i+"  "+x[i]);
        for(int i=0;i<n;i++){
            w[i] = w[i] * x[i];
            p[i] = p[i] * x[i];
        }
        for(int i=0;i<n;i++){
            profit = profit + p[i];
            weight = weight + w[i];
        }
        System.out.println("Max profit: "+profit);
        System.out.println("Weight: "+weight);    
    }

//Driver Code    
    public static void main(String[] args) {
        
        System.out.println("Enter no of objects");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        float[] p = new float[n];
        float[] w = new float[n];
        float[] c = new float[n];
//Input Weight        
        for(int i=0;i<n;i++){
            System.out.print("Enter Weights - "+(i+1)+" : ");
             w[i] = sc.nextInt();
        } 
//Input Profit or value        
        for(int i=0;i<n;i++){
                System.out.print("Enter profit - "+(i+1)+" : ");
             p[i] = sc.nextInt();
        } 
        for(int i=0;i<n;i++)
             c[i] = w[i]/p[i];
       
        System.out.print("Enter Knapsack Size: ");
        int m = sc.nextInt();
//For Ratio : P/W        
        for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n-1; j++) { 
            if (c[i] < c[j]) {

            float temp = c[j]; 
            c[j] = c[j+1]; 
            c[j+1] = temp; 
            
            temp = p[j]; 
            p[j] = p[j+1]; 
            p[j+1] = temp; 
            
            temp = w[j]; 
            w[j] = w[j+1]; 
            w[j+1] = temp; 
            
           } 
        } 
       }
        
        System.out.println("Items are:");
         System.out.println("Items\tWeight\tProfits ");
         for(int i = 0 ; i < n ; i++){
             System.out.println("x["+(i+1)+"]\t"+w[i]+"\t"+p[i]);
         }
      knapsack(n,m,w,p);
        
        
    }
}
