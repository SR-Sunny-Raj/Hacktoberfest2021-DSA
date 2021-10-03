package Graphs;

import java.util.LinkedList;
import java.util.Queue;

public class ZeroOneMatrix {
	static class Pair{
		int x;
		int y;
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int[][] solve(int[][] matrix){
		Queue<Pair> q = new LinkedList<>();
		int[][] dir = {{1,0},{0,1},{0,-1},{-1,0}};
		boolean[][] visited = new boolean[matrix.length][matrix[0].length];
		for(int i=0;i<matrix.length;i++){
			for(int j=0;i<matrix[0].length;j++){
				if(matrix[i][j]==0){
					//at level 1
					q.add(new Pair(i, j));
					visited[i][j] = true;
				}
			}
		}
		int level = 0;
		while(!q.isEmpty()){
			level++;
			int size = q.size();
			while(size>0){
				size--;
				Pair p = q.poll();
				for(int i=0;i<4;i++){
					//new coordinates -> to be checked
					int r = p.x+dir[i][0];
					int c = p.y+dir[i][1];
					//Validity check
					if(r>=0 && r<matrix.length&& c>=0 && c<matrix[0].length){
						if(!visited[r][c]){
							matrix[r][c] = level;
							q.add(new Pair(r, c));
							visited[r][c] = true;
						}
					}
				}
			}
		}
		return matrix;

	}
}
