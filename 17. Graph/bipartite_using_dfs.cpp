
#include<bits/stdc++.h>
using namespace std;



checkadj(vector<int> adj[],int s,vector<int> &colour)
{

    for(auto it: adj[s])
    {
        if(colour[it]==-1)
        {
            colour[it]=1-colour[s];
            if(!checkadj(adj,it,colour))
                return false;
        }
        else if(colour[it]==colour[s])
        {
            return false;
        }
    }
    return true;
}



bool colouring(vector<int> adj[],int v)
{
    vector<int> colour(v,-1);

    for(int i=0;i<v;i++)
    {
        if(colour[i]==-1)
        {
            colour[i]=1;
            if(!checkadj(adj,i,colour))
                return false;
        }

    }
    return true;
}



int main()
{

    int v;
    cin>>v;

    vector<int> adj[v];

    int e;
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    bool ans=colouring(adj,v);
    if(ans)
        cout<<"bipartite";
    else
        cout<<"not bipartite";

    return 0;
}
