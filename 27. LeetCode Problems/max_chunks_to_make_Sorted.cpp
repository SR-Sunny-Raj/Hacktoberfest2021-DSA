/*

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.



*/


class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
       int n=a.size();
     
        vector<int>v=a;
        sort(v.begin(),v.end());
        
        vector<int>pm(n); pm[0]=a[0];
        for(int i=1;i<n;i++){
            pm[i]=max(a[i],pm[i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pm[i]==v[i]) ans++;
        }
        return ans;
    }
  
};

