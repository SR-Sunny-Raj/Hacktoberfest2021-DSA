package Graphs;

import java.util.ArrayList;
import java.util.Stack;

public class AWalkToRemember {
	//using kosaraju
	public int[] walk(ArrayList<ArrayList<Integer>> graph,int v){
		Stack<Integer> st = new Stack<>();
		boolean[] visited = new boolean[v];
		// Fill up the stack
		for(int i=0;i<v;i++){
			if(!visited[i]){
				dfs(graph, visited, i, st);
			}
		}
		// reverse the link
		ArrayList<ArrayList<Integer>> newGraph = transpose(graph,v);

		// dfs on travsersed link component
		int[] ans = new int[v];
		visited = new boolean[v];
		Stack<Integer> nst = new Stack<>();
		while(!st.empty()){
			int curr = st.pop();
			if(!visited[curr]){
				dfs(newGraph, visited, curr, nst);
				//if stack contains more than 1 element, put 1 in the array
				if(nst.size()>1){
					while(!st.isEmpty()){
						ans[st.pop()-1] = 1;
					}
				}else{
					ans[st.pop()-1] = 0;
				}
			}
		}
		return ans;

	}
	public void dfs(ArrayList<ArrayList<Integer>> graph, boolean[] visited, int src, Stack<Integer> st){
		visited[src] = true;
		for(int nbr:graph.get(src)){
			if(!visited[nbr]){
				dfs(graph, visited, nbr, st);
			}
		}
		st.push(src);
	}
	public ArrayList<ArrayList<Integer>> transpose(ArrayList<ArrayList<Integer>> graph, int v){
		ArrayList<ArrayList<Integer>> ng = new ArrayList<>();
		for(int i=0;i<v;i++) ng.add(new ArrayList<>());
		for(int i=0;i<v;i++){
			for(int k:graph.get(i)){
				ng.get(k).add(i);
			}
		}
		return ng;
	}
}
