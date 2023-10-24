package Graphs;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

public class ChefAndReversing {
	static class Pair implements Comparable<Pair>{
		int v;
		int d;
		Pair(int v, int d){
			this.v = v;
			this.d = d;
		}
		public int compareTo(Pair p){
			return this.d-p.d;
		}
	}
	public static void main(String[] args) {
		// BFS
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int m = scn.nextInt();
		HashMap<Integer,ArrayList<Pair>> map = new HashMap<>();
		for(int i=0;i<n;i++) map.put(i, new ArrayList<>());
		for(int i=0;i<m;i++){
			//0 -> 0 links to reverse , 1 - 1 link to reverse
			int x = scn.nextInt();
			int y = scn.nextInt();
			map.get(x).add(new Pair(y, 0));//can go to y without reversing a link
			map.get(y).add(new Pair(x, 1));//can go to x by reversing a link
		}
		scn.close();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[n];
		pq.add(new Pair(1, 0));
		while(!pq.isEmpty()){
			Pair rem = pq.remove();
			if(visited[rem.v]) continue;
			visited[rem.v] = true;
			if(rem.v==n) {
				System.out.println(rem.d);//reached the dest
				return;
			}
			for(Pair p:map.get(rem.v)){
				pq.add(new Pair(p.v, rem.d+p.d));
			}
		}
		System.out.println(-1);
	}
}
