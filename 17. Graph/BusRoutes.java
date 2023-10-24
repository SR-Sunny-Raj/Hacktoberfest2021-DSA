package Graphs;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
// 4 Test cases failed
public class BusRoutes {
	public int numBusesToDestination(int[][] routes, int src, int dest) {
        HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
        int max = fillMap(routes,map);
        boolean[] visited = new boolean[max+1];
        Queue<Pair>q = new LinkedList<>();
        q.add(new Pair(src,-1,0));
        //DFS
        while(!q.isEmpty()){
            Pair rem = q.remove();
            if(rem.index!=-1){
                visited[rem.v] = true;
            }
            if(rem.v==dest) return rem.count;
            ArrayList<Integer> temp =  map.get(rem.v);
            for(int i=0;i<temp.size();i++){
                for(int j=0;j<routes[temp.get(i)].length;j++){
                    if(!visited[routes[temp.get(i)][j]]){
                        // System.out.println(routes[temp.get(i)][j]);
                        if(rem.index==i){
                            q.add(new Pair(routes[temp.get(i)][j],i,rem.count));
                        }else{
                             q.add(new Pair(routes[temp.get(i)][j],i,rem.count+1));
                        }
                    }
                }
            }
        }
        return -1;
    }
    class Pair{
        int v;
        int index;
        int count;
        Pair(int v, int index, int count){
            this.v = v;
            this.index = index;
            this.count = count;
        }
    }
    int fillMap(int[][] routes,HashMap<Integer,ArrayList<Integer>> map){
        int max = 0;
        for(int i=0;i<routes.length;i++){
            for(int j=0;j<routes[i].length;j++){
                max = Math.max(routes[i][j],max);
                if(map.containsKey(routes[i][j])){
                    ArrayList<Integer> temp = map.get(routes[i][j]);
                    temp.add(i);
                    map.put(routes[i][j],temp);
                }else{
                    ArrayList<Integer> temp = new ArrayList<>();
                    temp.add(i);
                    map.put(routes[i][j], temp);
                }
            }
        }
        return max;
    }
}
