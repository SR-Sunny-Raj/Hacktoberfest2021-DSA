package Graphs;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class IsBipartite {
	class Pair{
        int v;
        int level;
        Pair(int v, int level){
            this.v = v;
            this.level = level;
        }
    }
    public boolean isBipartite(int[][] graph) {
        int[] visited = new int[graph.length];
        Arrays.fill(visited,-1);
        for(int i=0;i<graph.length;i++){
            if(visited[i]==-1){
                boolean ans = help(graph,visited, i);
                if(!ans) return false;
            }
        }
        return true;
    }
    public boolean help(int[][] graph,int[] visited, int src){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(src,0));
        while(!q.isEmpty()){
            Pair rem = q.remove();
            if(visited[rem.v]!=-1){
                if(visited[rem.v]!=rem.level) return false;
            }
            visited[rem.v] = rem.level;
            for(int v:graph[rem.v]){
                if(visited[v]==-1){
                    q.add(new Pair(v, rem.level+1));
                }
            }
        }
        return true;
    }
}
