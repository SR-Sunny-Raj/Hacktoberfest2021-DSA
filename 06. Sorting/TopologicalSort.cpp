#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> Graph[],int s,int e)
{
    Graph[s].push_back(e);
    // Graph[e].push_back(s);
}



vector<int> topological(vector<int> graph[],int s)
{
    vector<int> result;   
    queue<int> q;
    vector<int> indegree(s,0);
    
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            indegree[graph[i][j]]++;
        }
    }

    for(int k=0;k<indegree.size();k++)
    {
        if(indegree[k]==0)
        {
            q.push(indegree[k]);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for(auto adj = graph[v].begin();adj!=graph[v].end();adj++)
        {
            indegree[*adj]--;
            if(indegree[*adj]==0)
            {
                q.push(*adj);
            }
        }        
    }

    
    return result;
}



int main()
{
    int size = 5;
    vector<int> graph[size];

    // graph formation
    addEdge(graph,0,1);   
    addEdge(graph,0,2);   
    addEdge(graph,1,3);   
    addEdge(graph,1,2);   
    addEdge(graph,2,3);   
    addEdge(graph,2,4);   
      
    
    
    cout<<endl<<endl;
    vector<int> result = topological(graph,size);
    cout<<"The sorted graph is\n";
    for(int i: result)
    {
        cout<<i<<" ";
    }
}