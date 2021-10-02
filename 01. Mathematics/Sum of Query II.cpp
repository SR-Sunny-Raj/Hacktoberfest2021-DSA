// Problem link: https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1

// Solution:-

   vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        int aSum[n];
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum=sum+arr[i];
            aSum[i+1]=sum;
        }
        
        vector<int>res;
        for(int i=0; i<(2*q); i=i+2)
        {
            if(queries[i]==1)
                res.push_back(aSum[queries[i+1]]);
            else
                res.push_back(aSum[queries[i+1]]-aSum[queries[i]-1]);
        }
        
        return res;
    }
