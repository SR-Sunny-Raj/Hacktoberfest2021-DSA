 // We will find radial boundary 
import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    // write ur code here
    
    int n=scn.nextInt();
    int temp;
    temp=n;
    int nst=2*n-1;
    int nsp=0;
    for(int i=1; i<=2*n-1; i++){
        int lhs=n;
        for(int j=1; j<=nsp; j++){
            System.out.print(lhs +"\t");
            lhs--;
        }
        for(int j=1; j<=nst; j++){
            System.out.print(temp +"\t");
        }
        int rhs=temp+1;
        for(int j=1; j<=nsp; j++){
            System.out.print(rhs +"\t");
            rhs++;
        }
        
        
        if(i<n){
            nsp++;
            nst=nst-2;
            temp--;
        }else{
            nsp--;
            nst=nst+2;
            temp++;
        }
        System.out.println();
        
    }

  }
}
