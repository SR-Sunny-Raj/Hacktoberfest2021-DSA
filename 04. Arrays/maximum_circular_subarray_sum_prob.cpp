#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        int max_sum=0;
        int sum_for_kadane=0;
        int actual_kadane=0;
        int max_sum_actual_kadane=0;
        int result=0;
        int total_sum=0;
        int flag_for_all_negative=0;
        int max_in_case_of_all_negative=INT_MIN;
        for(int i=0;i<num;i++){
            if(arr[i]>0)
            flag_for_all_negative=-1;
            sum_for_kadane+=arr[i]*(-1);
            max_sum=max(max_sum,sum_for_kadane);
            total_sum+=arr[i]*(-1);
            if(sum_for_kadane<0)
            sum_for_kadane=0;
            actual_kadane+=arr[i];
            max_sum_actual_kadane=max(max_sum_actual_kadane,actual_kadane);
            if(actual_kadane<0)
            actual_kadane=0;
            max_in_case_of_all_negative=max(max_in_case_of_all_negative,arr[i]);
        }
        if(flag_for_all_negative==0)
        return max_in_case_of_all_negative;
        else{
        result=(total_sum-max_sum)*(-1);
        return max(result,max_sum_actual_kadane);
        }
        // your code here
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends