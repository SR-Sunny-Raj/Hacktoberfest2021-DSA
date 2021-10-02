class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int fac[n];
        for(int i=0;i<n;i++)
        {
            if(i==0)
                fac[i]=1;
            else
                fac[i]=fac[i-1]*i;
        }
        k=k-1;
        //represent k in factorial number system
        vector<int> num(n,0);
        int ind=n-1;
        while(k>0)
        {
            if(fac[ind]>k)
                ind--;
            else
            {
                num[ind]=k/fac[ind];
                k=k%fac[ind];
                ind--;
            }
        }
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        int res=0;
        for(int i=n-1;i>=0;i--)
        {
            res=res*10+nums[num[i]];
            nums.erase(nums.begin()+num[i]);
            
        }
        
        
        stringstream ss;
        ss<<res;
        s=ss.str();
        return s;
        
    }
};
