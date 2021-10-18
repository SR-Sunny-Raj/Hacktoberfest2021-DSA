class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n=dun.size();
        int m=dun[0].size();
        int a[n][m];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                    a[i][j]=min(0,dun[i][j]);
                else if(i==n-1)
                    a[i][j]=min(0,dun[i][j]+a[i][j+1]);
                else if(j==m-1)
                    a[i][j]=min(0,dun[i][j]+a[i+1][j]);
                else
                    a[i][j]=min(0,dun[i][j]+max(a[i+1][j],a[i][j+1]));
            }
        }
        return abs(a[0][0])+1;
    }
};
