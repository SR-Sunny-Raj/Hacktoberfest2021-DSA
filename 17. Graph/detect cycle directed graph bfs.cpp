
#include<bits/stdc++.h>
using namespace std;


void check(vector<int> adj[],int v)
{
    vector<int> indeg(v,0);

    for(int i=0;i<v;i++)
    {
        for(auto it: adj[i])
            {
                indeg[it]++;
            }
    }
    queue<int> q;

    for(int i=0;i<v;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }



    int c=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        c++;
        for(auto it:adj[node])
        {
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }
    }

    if(c!=v)
    {

        cout<<"cycle detected!!!";

    }
    else
    {
        cout<<"no cycle";
    }


}

int main()
{
    int v;
    cin>>v;

    int e;
    cin>>e;

    vector<int> adj[v];

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;

        adj[s].push_back(d);
    }

    check(adj,v);


    return 0;
}
