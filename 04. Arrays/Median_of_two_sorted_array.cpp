//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> a;
        int i=0,j=0;
        while(i<n or j<m)
        {
            if(i<n and j<m)
            {
                if(nums1[i]<=nums2[j])
                {
                    a.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    a.push_back(nums2[j]);
                    j++;
                }
            }
            else if(i==n)
            {
                a.push_back(nums2[j]);
                j++;
            }
            else
            {
                a.push_back(nums1[i]);
                i++;
            }
        }
        
        if((n+m) % 2==0)
              {
                 double c= a[(n+m)/2];
                 double d = a[((n+m)/2)-1];
                 double ans = (c+d)/2.0000;
                 return ans;
              }
        else
              return a[(n+m)/2];
        
    }
};
