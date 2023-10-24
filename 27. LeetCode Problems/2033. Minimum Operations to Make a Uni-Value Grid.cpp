class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mi=-1;
        int r=grid.size();
        int c=grid[0].size();
        int sum=0;
        set<int>s;
        vector<int>v;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                s.insert(grid[i][j]%x);
                v.push_back(grid[i][j]);
            }
        }
        if(s.size()>1) return -1;
        sort(v.begin(),v.end());
        
        int n=v.size()/2;
        
        for(int i=0;i<v.size();i++)
        {
            sum+=(abs(v[n]-v[i]))/x;
        }
        
        return sum;
        
    }
};