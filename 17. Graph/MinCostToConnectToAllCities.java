package Graphs;

import java.util.PriorityQueue;

public class MinCostToConnectToAllCities {
	public static void main(String[] args) {
		int[][] graph = {{0, 1, 1, 100, 0, 0},
		{1, 0, 1, 0, 0, 0},
		{1, 1, 0, 0, 0, 0},
		{100, 0, 0, 0, 2, 2},
		{0, 0, 0, 2, 0, 2},
		{0, 0, 0, 2, 2, 0}};
		int x = (mst(graph));
		System.out.println();
		System.out.println(x);
	}
	static class Pair implements Comparable<Pair>{
		int v;
		int wt;
		Pair(int v,int wt){
			this.v = v;
			this.wt = wt;
		}
		public int compareTo(Pair p){
			return this.wt-p.wt;
		}
	}
	static int mst(int[][] graph){
		boolean[] visited = new boolean[graph.length];
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(0, 0));
		int count = 0;
		while(!pq.isEmpty()){
			Pair rem = pq.remove();
			if(visited[rem.v]) continue;
			visited[rem.v] = true;
			count+=rem.wt;
			for(int i=0;i<graph[rem.v].length;i++){
				if(graph[rem.v][i]!=0 && !visited[i]){
					pq.add(new Pair(i, graph[rem.v][i]));
				}
			}
		}
		return count;
	}
}
