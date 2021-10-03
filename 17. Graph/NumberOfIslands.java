package Graphs;

public class NumberOfIslands {
	public int numIslands(char[][] grid) {
        int count = 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,visited);
                    count++;
                }
            }
        }
        return count;
    }
    public void dfs(char[][] grid, int i, int j, boolean[][] visited){
        if(i>=grid.length||j>=grid[0].length||i<0||j<0||visited[i][j]||grid[i][j]=='0') return;
        visited[i][j] = true;
        dfs(grid,i+1,j,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);
        dfs(grid,i,j+1,visited);
    }
}
