package Graphs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class KahnsAlgorithm {
	public static void main(String[] args) {
		
	}
	static int[] findOrder(int numCourses, ArrayList<ArrayList<Integer>> graph){
		int[] inDegree = new int[numCourses];
		int [] ans = new int[numCourses];
		for(int i=0;i<numCourses;i++){
			for(int n:graph.get(i)){
				inDegree[n]++;
		}
		}
		Queue<Integer> q = new LinkedList<>();
		for(int i=0;i<numCourses;i++){
			if(inDegree[i]==0){
				q.add(i);
			}
		}
		int index =0;
		while(!q.isEmpty()){
			int rem = q.remove();
			ans[index] = rem;
			rem++;
			for(int n:graph.get(rem)){
				inDegree[n]--;
				if(inDegree[n]==0) q.add(n);
			}
		}
		if(index==numCourses){
			return ans;
		}
		return new int[]{-1};
		
	}
}
