package Graphs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CourseSchedule {
	public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        for(int i = 0; i < numCourses; i++){
            graph[i] = new ArrayList<>();
        }
        int[] inDegree = new int[numCourses];
        for(int[] p:prerequisites){
            int u = p[0];
            int v = p[1];
            graph[u].add(v);
            inDegree[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.add(i);
            }
        }
        int[] ans = new int[numCourses];
        int i = numCourses-1;
        while(!q.isEmpty()){
            int rem = q.remove();
            ans[i] = rem;
            i--;
            for(int v:graph[rem]){
                if(--inDegree[v]==0) q.add(v);
            }
        }
        if(i==-1){
            return ans;
        }
        return new int[0];
}
	
}
