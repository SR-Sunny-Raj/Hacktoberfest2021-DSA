//Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, 
//the task is to find the element which is repeated and number of times it is repeated.
//Note: If there's no repeating element, Return {-1,-1}.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        pair<int, int> result={-1,-1};
        int left=0,right=n-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[0]+mid<=arr[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        result.first=arr[mid];
        result.second=n-(arr[n-1]-arr[0]);
        return result;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
}
