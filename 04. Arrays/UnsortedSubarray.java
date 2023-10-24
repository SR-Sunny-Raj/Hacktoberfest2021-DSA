//Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
//approach used.

//1) Find the candidate unsorted subarray
//a) Scan from left to right and find the first element which is greater than the next element. 
//Let s be the index of such an element. In the above example 1, s is 3 (index of 30).
//b) Scan from right to left and find the first element (first in right to left order) 
//which is smaller than the next element (next in right to left order). Let e be the index of such an element
// In the above example 1, e is 7 (index of 31).

//2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. 
//If not, then include more elements in the subarray.
//a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max.
//min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
//b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element.
//There is no such element in above example 1.
//c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. 
//In the above example 1, e is changed to 8 (index of 35)

//3) Print s and e.
public class UnsortedSubarray {

	static void unsortedArray(int [] arr, int n)
	{
		int s=0; 
		int e =n-1;
		int i;
		int max; 
		int min ;
		
		//step 1(a)
		for(s=0;s<n-1;s++)
		{
			if (arr[s]>arr[s+1])
				break;
		}

		
		//step 1(b)
		 for(e = n - 1; e > 0; e--) 
	      { 
	        if(arr[e] < arr[e-1]) 
	          break; 
	      } 
		 
		// step 2(a) of above algo 
	      max = arr[s]; min = arr[s]; 
	      for(i = s + 1; i <= e; i++) 
	      { 
	        if(arr[i] > max) 
	          max = arr[i]; 
	        if(arr[i] < min) 
	          min = arr[i]; 
	      } 
	        
	      // step 2(b) of above algo 
	      for( i = 0; i < s; i++) 
	      { 
	        if(arr[i] > min) 
	        {   
	          s = i; 
	          break; 
	        }       
	      }  
	        
	      // step 2(c) of above algo 
	      for( i = n -1; i >= e+1; i--) 
	      { 
	        if(arr[i] < max) 
	        { 
	          e = i; 
	          break; 
	        }  
	      }   
	            
	      // step 3 of above algo 
	      System.out.println(" The unsorted subarray which"+ 
	                         " makes the given array sorted lies"+ 
	                       "  between the indices "+s+" and "+e); 
	      return;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		UnsortedSubarray us=new UnsortedSubarray();
		int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60}; 
	      int n = arr.length; 
	      us.unsortedArray(arr, n);
	}

}
