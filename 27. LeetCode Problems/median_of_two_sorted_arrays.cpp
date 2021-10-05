/*Q)Given two sorted arrays nums1 and nums2 of size m and n
 respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

*/



#include<bits/stdc++.h>
#define ml INT_MAX
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    nums1.push_back(ml);
    nums2.push_back(ml);
    vector<long>ans;
	int i=0,j=0;
	while(((i+j)<(nums1.size())+(nums2.size())) && i<nums1.size() && j<nums2.size())
	{
	   
	    if(nums1[i]>nums2[j])
	    {
	       // cout<<nums2[j]<<endl;
	        ans.push_back(nums2[j]);
	        j++;
	    }
	    else if(nums1[i]<nums2[j])
	    {
	        ans.push_back(nums1[i]);
	        i++;
	    }
	    else{   
	        ans.push_back(nums1[i]);
	        ans.push_back(nums2[j]);
	        i++;
	        j++;
	    }
	   
	}
    long siz = ans.size()-2;

	if(siz%2 == 0)
	{
	    double as = ((double)ans[siz/2]+(double)ans[(siz/2)-1])/2;
	    return as;
	}
	else{
	    double b = (double)ans[siz/2];
	    return b;
	}
}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//code goes here
    vector<int>arr1={1,2},arr2={3,4};
    cout<<findMedianSortedArrays(arr1,arr2)<<endl;
	
return 0;
}