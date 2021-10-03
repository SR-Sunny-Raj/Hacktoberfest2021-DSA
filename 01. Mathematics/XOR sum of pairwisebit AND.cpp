int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n,m,i,j;
        n=arr1.size();
        m=arr2.size();
        int ans1,ans2;
        ans1=arr1[0];
        ans2=arr2[0];
        for(i=1;i<n;i++)
            ans1=ans1^arr1[i];
        for(i=1;i<m;i++)
            ans2=ans2^arr2[i];
        return ans1&ans2;
        
    }