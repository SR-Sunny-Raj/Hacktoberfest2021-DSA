package Graphs;

public class WallsAndGates {
	public static void main(String[] args) {
		
	}
	public static int[][] solve(int[][] rooms){
		for(int i=0;i<rooms.length;i++){
			for(int j=0;j<rooms[i].length;j++){
				if(rooms[i][j]==0){
					//distance from the 
					dfs(i,j,0,rooms);
				}
			}
		}
		return rooms;
	}
	static void dfs(int i, int j, int count,int[][] grid){
		if(i<0||i>=grid.length||j<0||j>=grid[0].length||grid[i][j]<count) return;
		grid[i][j] = count;
		dfs(i+1, j, count, grid);
		dfs(i-1, j, count, grid);
		dfs(i, j+1, count, grid);
		dfs(i, j-1, count, grid);
	}
}
