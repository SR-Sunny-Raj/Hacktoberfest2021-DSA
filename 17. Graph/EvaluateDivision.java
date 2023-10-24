package Graphs;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map.Entry;

public class EvaluateDivision {
	public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        HashMap<String,HashMap<String,Double>>map= build(equations,values);
        double[] ans = new double[queries.size()];
        for(int i=0;i<queries.size();i++){
            ans[i] = dfs(map,new HashSet<>(),queries.get(i).get(0),queries.get(i).get(1));
        }
        return ans;
        
    }
    public double dfs(HashMap<String,HashMap<String,Double>>graph, HashSet<String> visited,String a, String b){
        if(!graph.containsKey(a)){
            // graph doesn't contain that vx
            return -1.0;
        }
        if(graph.get(a).containsKey(b)){
            //direct edge is present
            return graph.get(a).get(b);
        }
        visited.add(a);
        for(Entry<String, Double> n: graph.get(a).entrySet()){
            if(!visited.contains(n.getKey())){
                double rWeight = dfs(graph,visited,n.getKey(),b);
                if(rWeight!=-1){
                    return rWeight * n.getValue();
                }
            }
        }
        return -1;
    }
    
    
    
    public HashMap<String,HashMap<String,Double>> build(List<List<String>> equations, double[] values)       {
        HashMap<String,HashMap<String,Double>> graph = new HashMap<>();
        for(int i=0;i<equations.size();i++){
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            double val = values[i];
            graph.putIfAbsent(a,new HashMap<String,Double>());
            graph.get(a).put(b,val);
            graph.putIfAbsent(b,new HashMap<String,Double>());
            graph.get(b).put(a,1/val);
        }    
        return graph;
    }
}
