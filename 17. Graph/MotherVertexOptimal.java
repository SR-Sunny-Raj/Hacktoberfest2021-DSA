package Graphs;

import java.util.ArrayList;

public class MotherVertexOptimal {
	// Traversing from the mother vx -> it will appear on top of the stack
	public int mother(ArrayList<ArrayList<Integer>> graph,int v){
		int mother = -1;
		boolean[] visited = new boolean[v];
		for(int i=0;i<v;i++){
			if(!visited[i]){
				dfs(graph, i, visited);
				mother = i;
			}
		}
		visited = new boolean[v];
		dfs(graph, mother, visited);
		for(int i=0;i<v;i++){
			if(!visited[i]){
				mother = -1;
			}
		}
		return mother;
	}
	public void dfs(ArrayList<ArrayList<Integer>> graph, int src, boolean[] visited){
		visited[src] = true;
		for(int nbr:graph.get(src)){
			if(!visited[nbr]){
				dfs(graph, nbr, visited);
			}
		}
	}
}
