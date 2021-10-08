import java.util.*;
public class Mountain
{
    public  static int peakIndexInMountainArray(int n, int[] arr)
    {
        int start =0;
        int end= arr.length-1;
        while(start<end)
        {
            int mid = start +(end - start) / 2;
            if(arr[mid]>arr[mid+1])
            {
                end=mid;
            }
            else{
                start = mid+1;
            }
            
        }
        return start;
    }
    
	public static void main(String[] args) {
	    
	    Scanner sc = new Scanner(System.in);
	    int n =sc.nextInt();
	    
	    int[] arr = new int[n];
	    for(int i=0;i<n;i++)
	    {
	        arr[i] =sc.nextInt();
	    }
	    int ans = peakIndexInMountainArray(n,arr);
	    System.out.println(ans);
	    
	}
}
