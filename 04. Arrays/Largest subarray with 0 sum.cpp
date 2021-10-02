// Problem Statement: Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Solution:-

  int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int res=0;
        int preSum=0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            preSum+=A[i];
            if(preSum==0) res=i+1; 
            if(mp.find(preSum)==mp.end())
                mp.insert({preSum,i});
            if(mp.find(preSum)!=mp.end())
                res=max(res, i - mp[preSum]);
            
        }
        return res;
    }
