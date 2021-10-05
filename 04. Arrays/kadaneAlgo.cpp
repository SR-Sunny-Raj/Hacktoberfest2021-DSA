 int maxSubarraySum(int arr[], int n){
      int curr=0,maxi=INT_MIN;  
     for(int i=0;i<n;i++)
     {
         curr=curr+arr[i];
         maxi=max(maxi,curr);
         if(curr<0)
         {
             curr=0;
         }
     }
     return maxi;
    }