import java.io.*;
import java.util.*;

class BfsIter
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        int n=5,i;  //number of nodes
        boolean vis[]=new boolean[n];
        ArrayList<Integer> g[]=new ArrayList[n];    //graph
        for(i=0;i<5;i++)
        g[i]=new ArrayList<>();
        int m=Integer.parseInt(bu.readLine());  //number of edges
        for(i=0;i<m;i++)
        {
            String s[]=bu.readLine().split(" ");
            int u=Integer.parseInt(s[0])-1,v=Integer.parseInt(s[1])-1;
            g[u].add(v);
            g[v].add(u);
        }
        bfs(g,vis,0);
    }

    static void bfs(ArrayList<Integer> g[],boolean v[],int n)   //iterative bfs
    {
        Queue<Integer> q=new LinkedList<>();
        v[n]=true;
        q.add(n);
        while(!q.isEmpty())
        {
            int p=q.poll();
            System.out.print(p+1+" ");
            for(int x:g[p])
            if(!v[x])
            {
                v[x]=true;
                q.add(x);
            }
        }
    }
}
