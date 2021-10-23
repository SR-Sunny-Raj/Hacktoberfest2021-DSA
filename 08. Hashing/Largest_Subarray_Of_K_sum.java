/*
  Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array 
  with the sum of the elements equal to the given value K.
  
  Input :
  A[] = {10, 5, 2, 7, 1, 9}
  K = 15
  Output : 4
  Explanation:
  The sub-array is {5, 2, 7, 1}.
*/

import java.io.*;
import java.util.*;

class LongSubarray{
  
	static int lenOfLongSubarray(int[] arr, int n, int k)
	{
			
			HashMap<Integer, Integer> mp = new HashMap<>();
			int sum = 0, maxLen = 0;
    
			for (int i = 0; i < n; i++) {
				
				sum += arr[i];
				
				if (sum == k)
					maxLen = i + 1;
        
				if (!mp.containsKey(sum)) {
					mp.put(sum, i);
				}

				if (mp.containsKey(sum - k)) {
					
					if (maxLen < (i - mp.get(sum - k)))
						maxLen = i - mp.get(sum - k);
				}
			}
			
			return maxLen;			
	}

	public static void main(String args[])
	{
			int[] arr = {10, 5, 2, 7, 1, 9};
			int n = arr.length;
			int k = 15;
			System.out.println(lenOfLongSubarray(arr, n, k));
	}
}

