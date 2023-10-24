//Leetcode Medium Level

//Problem link : https://leetcode.com/problems/number-of-islands/


class Solution {
    void mark_cur_island(vector<vector<char>> &matrix, int x, int y, int r, int c){
        
        //Corner Cases for matrix
        if(x<0 || x >=r || y<0 || y>=c || matrix[x][y]!='1'){
            return;
        }
        
        //Consider this cell as visited
        matrix[x][y] = '2';
        
        mark_cur_island(matrix,x+1,y,r,c); //DOWN
        mark_cur_island(matrix,x-1,y,r,c); //TOP
        mark_cur_island(matrix,x,y+1,r,c); //RIGHT
        mark_cur_island(matrix,x,y-1,r,c); //LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rows = grid.size();
        if(rows==0)
            return 0; //Empty grid, return zero island
        int columns = grid[0].size();
        int islands = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]=='1'){
                    mark_cur_island(grid,i,j,rows,columns);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};
