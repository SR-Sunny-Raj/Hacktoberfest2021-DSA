//Problem : 1905. Count Sub Islands
//Link : https://leetcode.com/problems/count-sub-islands/

//Using Dfs Approach and finding union with every componenet of sub island of 2 with 1 to count is sub island


//Code

// ---------------------------START-----------------------------------//

class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,int &flag){
        
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]==0){
            return;
        }
        
        if(grid1[i][j]!=grid2[i][j]){
            flag = 0;
        } 
        
        grid2[i][j] = 0;
        
        dfs(i-1,j,grid1,grid2,flag);
        dfs(i,j-1,grid1,grid2,flag);
        dfs(i+1,j,grid1,grid2,flag);
        dfs(i,j+1,grid1,grid2,flag);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int ans=0;
        int n=grid1.size();
        int m=grid1[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid2[i][j]==1){
                    
                    int flag=1;
                    dfs(i,j,grid1,grid2,flag);
                    if(flag){
                       ans+=1;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};