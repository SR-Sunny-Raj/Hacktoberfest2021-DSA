package Graphs;

import java.util.ArrayList;
import java.util.Stack;


public class Kosaraju {
	static int kosaraju(ArrayList<ArrayList<Integer>> list,int n){
		//fill the stack
		Stack<Integer> st = new Stack<>();
		boolean[] visited = new boolean[n];
		for(int i=0;i<n;i++){
			if(!visited[i]){
				dfs(list, visited, i, st);
			}
		}
		//reverse the edges
		ArrayList<ArrayList<Integer>> newGraph = transpose(list,n);

		//Specific order DFS
		visited = new boolean[n];
		int ans = 0;//counts connected component;
		while(st.size()>0){
			int cur = st.pop();
			if(!visited[cur]){
				dfs(newGraph, visited, cur);
				ans++;
			}
		}
		return ans;
	}
	static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[] visited,int cur, Stack<Integer> stack){
		visited[cur] = true;
		for(int v:graph.get(cur)){
			if(!visited[v]){
				dfs(graph, visited, v, stack);
			}
		}
		stack.add(cur);
	}
	static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[] visited,int cur){
		visited[cur] = true;
		for(int v:graph.get(cur)){
			if(!visited[v]){
				dfs(graph, visited, v);
			}
		}
	}
	static ArrayList<ArrayList<Integer>> transpose(ArrayList<ArrayList<Integer>> graph, int n){
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		for(int i=0;i<n;i++){
			result.add(new ArrayList<>());
		}
		for(int i=0;i<n;i++){
			for(int nbr:graph.get(i)){
				result.get(nbr).add(i);
			}
		}
		return result;
	}
}
