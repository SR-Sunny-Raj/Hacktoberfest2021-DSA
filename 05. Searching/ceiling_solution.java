// package DSA;

public class dsa2_Celing {
	 public static void main(String[] args) {
	        int[] arr = {1,3,5,7,9,12,14,15,17,29,34,37,46,58,100};
	        int target = 7;
	        int ans = FindAns(arr, target);
	        System.out.println("Ceil of the element is: " + ans);
	    }
	    static int FindAns(int[] arr, int target){
	        int start = 0;
	        int end = arr.length-1;
	        int mid=0;
	        int ceil = -1;
	        while(start<=end){
	            mid = start + (end - start)/2;
	            
//if we want to return target if it is present in array, then we can simply return it instead of returning ceil.
//	          if(arr[mid] == target){
//	              return arr[mid];
//	          }
	             if(arr[mid] > target){
	                ceil = arr[mid];
	              end = mid-1;

	            }
	            else {
	              start = mid + 1;
	          }
	        }
	        return ceil;
	    }
	    
}