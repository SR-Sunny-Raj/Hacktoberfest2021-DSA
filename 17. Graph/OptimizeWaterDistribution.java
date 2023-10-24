package Graphs;

import java.util.PriorityQueue;
// https://github.com/azl397985856/leetcode/blob/master/problems/1168.optimize-water-distribution-in-a-village-en.md
public class OptimizeWaterDistribution {
	public static void main(String[] args) {
		// int n = 5;
		// int[] wells = {1,2,2,3,2};
		// int[][] pipes = {{1,2,1},{2,3,1},{4,5,7}};
		
	}
	static class Pair implements Comparable<Pair>{
		int v;
		int wt;
		int pv;
		Pair(int v, int wt,int pv){
			this.v = v;
			this.wt = wt;
			this.pv = pv;
		}
		public int compareTo(Pair o){
			return this.wt-o.wt;
		}
	}
	static int findMin(int[][] graph){
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[graph.length];
		pq.add(new Pair(0,0,-1));
		int count =0;
		while(!pq.isEmpty()){
			Pair rem = pq.remove();
			if(visited[rem.v]) continue;
			visited[rem.v] = true;
			if(rem.pv!=-1){
				System.out.println(rem.pv);
			}
			count+=rem.wt;
			for(int i=0;i<graph[rem.v].length;i++){
				if(graph[rem.v][i]!=0 && !visited[i]){
					pq.add(new Pair(i, graph[rem.v][i],rem.v));
				}
			}
		}
		return count;
	}
}
