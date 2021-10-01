class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low=0, high= arr.size()-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(n==1)
            {
                return 0;
            }
            if(mid>0 && mid<arr.size()-1)
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                {
                    return mid;
                }
                else if(arr[mid-1]>arr[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(mid==0)
            {
                if(arr[0]>arr[1])
                {
                    return 0;
                }
                else 
                {
                    return 1;
                }
            }
            else if(mid == arr.size()-1)
            {
                if(arr[arr.size()-1]>arr[arr.size()-2])
                {
                    return arr.size()-1;
                }
                else 
                {
                    return arr.size()-2;
                }
            }
        }
        return -1;
    }
};
