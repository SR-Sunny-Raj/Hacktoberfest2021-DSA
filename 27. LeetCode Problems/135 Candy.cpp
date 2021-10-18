class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size();
        int t1[n];
        int t2[n];
        int ans=0;
        t1[0]=t2[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                t1[i]=t1[i-1]+1;
            else
                t1[i]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
                t2[i]=t2[i+1]+1;
            else
                t2[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            ans+=max(t1[i],t2[i]);
        }
        return ans;
    }
};
