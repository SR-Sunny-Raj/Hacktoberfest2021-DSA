package Graphs;

import java.util.Stack;

public class TopologicalSorting {
	public static void main(String[] args) {
		
	}
	static void topologicalSort(int[][] graph){
		boolean[] visited = new boolean[graph.length];
		Stack<Integer> st = new Stack<>();
		for(int i=0;i<visited.length;i++){
			if(!visited[i]){
				help(graph,i,visited,st);
			}
		}
		while(!st.isEmpty()){
			System.out.println(st.pop());
		}

	}
	static void help(int[][] graph, int i, boolean[] visited, Stack<Integer> st){
		visited[i] = true;
		for(int v:graph[i]){
			if(!visited[v]){
				help(graph, v, visited, st);
			}
		}
		st.push(i);
	}
}
