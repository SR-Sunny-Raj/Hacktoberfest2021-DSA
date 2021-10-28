import java.util.Arrays;
import java.util.Scanner;

public class MeanderingArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		
		    int m = scn.nextInt();
		    int arr[] = new int[m];
		    for(int j=0;j<m;j++)
		    {
		        arr[j]= scn.nextInt();        
		    }		
		rearrangeArray(arr,m);
	}
	
	public static void rearrangeArray(int arr[], int n)
    {
        Arrays.sort(arr);
        
        int [] tempArr = new int[n];
        
        int arrayIndex =0;
        
        for (int i=0,j =n-1; i <= n/2 || j> n/2 ; i++ ,j--)
        {
            if(arrayIndex < n)
            {
                tempArr[arrayIndex] = arr[i];
                arrayIndex++;
            }
            
            if(arrayIndex < n)
            {
                tempArr[arrayIndex] = arr[j];
                arrayIndex++;
            }
        }
        
        for (int i=0;i<n;i++)
        {
            arr[i] = tempArr[i];
        }
        
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i] + " ");
        }
    }
}


