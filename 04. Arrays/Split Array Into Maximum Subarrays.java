/*

    Time Complexity: O(N)
    Space Complexity: O(M)

    Where N is the size of an array and M is the max element in an array.

*/

import java.util.ArrayList;

public class Solution {
   public static int splitArray(ArrayList<Integer> arr){

       // Variable to store the size of an array.
       int n = arr.size();

       // Variable to store the max element of an array.
       int mx = arr.get(0);

       for (int i = 1; i < n; i++){
           mx = Math.max(arr.get(i), mx);
       }

       // Declaring hash array of size equal to max element and initializing it with 0.
       int[] hash=new int [mx + 1];

       for(int i=0;i<mx+1;i++){
           hash[i]=0;
       }

       // Updating hash array with last occurrences.
       for (int i = 0; i < n; i++){
           hash[arr.get(i)] = i;
       }

       // Variable to store the maximum index of last occurrences of all elements.
       int maxIdx = -1; 

       // Result variable.
       int res = 0; 

       // Iterating over array.
       for (int i = 0; i < n; i++){

           // Updating the max index.
           maxIdx = Math.max(maxIdx, hash[arr.get(i)]);
           
           // If max index is current index then incrementing the result.
           if (maxIdx == i){
               res++;
           }
       }
       return res;
   }
}
