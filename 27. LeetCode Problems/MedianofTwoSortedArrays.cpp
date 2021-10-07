#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size(), m=nums2.size();
        int lt=0, rt = n;
        while(lt<=rt)
        {
            int mid = (lt+rt)/2;
            int mid2 = (n+m+1)/2 - mid;
            int arr1_min = (mid>0)? nums1[mid-1] : INT_MIN;
            int arr1_max = (mid<n)? nums1[mid] : INT_MAX;
            int arr2_min = (mid2>0)? nums2[mid2-1] : INT_MIN;
            int arr2_max = (mid2<m)? nums2[mid2] : INT_MAX;
            if(arr1_min<=arr2_max && arr2_min<=arr1_max)
            {
                if((n+m)%2)
                    return double(max(arr1_min,arr2_min));
                else
                {
                    double f_ans = double(max(arr1_min,arr2_min)+min(arr1_max,arr2_max))/2.0;
                    return f_ans;
                }
            }
            else if(arr1_min>arr2_max)
                rt=mid-1;
            else
                lt=mid+1;
        }
        return 0; 
    }

int main()
{
        vector<int> nums1,nums2;
        nums1.push_back(2);
        nums1.push_back(3);
        nums1.push_back(4);
        nums1.push_back(7);
        nums1.push_back(9);
        nums2.push_back(2);
        nums2.push_back(5);
        nums2.push_back(6);
        nums2.push_back(7);
        nums2.push_back(10);
        nums2.push_back(11);
        nums2.push_back(12);
        cout<<findMedianSortedArrays(nums1,nums2);
        return 0;
}
