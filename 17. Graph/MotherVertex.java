package Graphs;

import java.util.ArrayList;
public class MotherVertex {
	public int findMotherVertex(int V, ArrayList<ArrayList<Integer>>adj)
    {
		//BRUTE Force
        // Code here
        boolean[] visited ;
        for(int i=0;i<V;i++){
            visited = new boolean[V];
            dfs(adj,visited,i);
            int count = 0;
            for(boolean v:visited){
                if(v) count++;
            }
            if(count==V) return i;
            
        }
        return -1;
    }
    private void dfs( ArrayList<ArrayList<Integer>> graph, boolean[] visited, int curr){
        visited[curr] = true;;
        for(int nbr:graph.get(curr)){
            if(!visited[nbr]){
                 dfs(graph,visited,nbr);
            }
        }
    }
}
