/*
    So the idea here is instead of doing 1 traversal form (0,0)->(n-1,n-1) and then 1 traversal from (n-1,n-1)->(0,0)
    We will do 2 traversals independtly from (0,0)->(n-1,n-1). Now lets's talk about state we can have 
[r1,c1,r2,c2] -> state we can have but this is O(n^4) we can reduce it to O(n^3) because manhattan distance remains same
i.e. (r1-0) + (c1-0) = (r2-0) + (c2-0) so the current state becomes [r1,c1,c2] and r2 = r1+c1-c2 
    */
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r1,int c1,int c2,int n)
    {
        int r2 = r1 + c1 - c2;//explanation in the above section 
        //if any of the current rows or colums goes out of bound or there is a thorn on a current block then return INT_MIN
        if(r1>=n || r2>=n || c1>=n || c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)//if we have already calculated the value for current state then return that value
            return dp[r1][c1][c2];
        //if we are right most bottom corner then simply return grid value
        if(r1==n-1 && c1 == n-1)
            return grid[r1][c1];
        //ans will be the ans for current state + future state
        int ans = grid[r1][c1];
        if(r1!=r2)//this is put in place to not pickup a cherry that is already picked up
            ans += grid[r2][c2];//if the cherry is not picked up already then pick it up
        //Now we need to take the max of 4 cases for both traversals
        //1.) Right Right
        //2.) Down Down
        //3.) Right Down
        //4.) Down Right
        int temp = max({cherry_picker(grid,dp,r1,c1+1,c2+1,n),cherry_picker(grid,dp,r1+1,c1,c2,n),
                       cherry_picker(grid,dp,r1,c1+1,c2,n),cherry_picker(grid,dp,r1+1,c1,c2+1,n)});
        ans += temp;//add it to the ans
        dp[r1][c1][c2] = ans;//memorise the answer
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,cherry_picker(grid,dp,0,0,0,n));
    }
