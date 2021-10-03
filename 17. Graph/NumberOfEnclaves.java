package Graphs;

public class NumberOfEnclaves {
	public int numEnclaves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1){
                    if(grid[i][j]==1){
                        find(grid,i,j);
                    }
                }
            }
        }
        int count = 0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
    public void find(int[][] grid, int i, int j){
        if(i<0||j<0||j>=grid[0].length||i>=grid.length||grid[i][j]==0) return;
        grid[i][j] = 0;
        find(grid,i-1,j);
        find(grid,i+1,j);
        find(grid,i,j+1);
        find(grid,i,j-1);
    }
}
