/*Problem Statement - You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, 
each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. 
Your plan has to work in any situation; even if the monsters know your path beforehand.*/

// Problem Link - https://cses.fi/problemset/task/1194/


#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'D', 'U', 'R', 'L'};
 
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> room(n, vector<char> (m, '#'));
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
    greater<pair<int, pair<int,int>>> > pq;
    
    vector<vector<int>> monsters(n, vector<int> (m, INT_MAX));
    
    int row=-1, col=-1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char ch;
            cin>>ch;
            room[i][j] = ch;
            if(ch=='M')
            {
                pq.push({0, {i,j}});
                monsters[i][j] = 0;
            }
            else if(ch=='A')
            {
                row=i, col=j;
            }
        }
    }
   
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        int dist = pq.top().first;
        pq.pop();
        
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<0 || Y<0 || X>=n || Y>=m || room[X][Y]=='#')
            {
                continue;
            }
            if(monsters[X][Y]>dist + 1)
            {
                monsters[X][Y] = dist+1;
                pq.push({monsters[X][Y], {X,Y}});
            }
        }
    }
    vector<vector<int>> human(n, vector<int> (m, INT_MAX));
    human[row][col] = 0;
    
    bool flag = false;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
    greater<pair<int, pair<int,int>>> > pq1;
    
    pq1.push({0, {row, col}});
    int row_f=-1, col_f=-1;
    int ans = -1;
    while(!pq1.empty())
    {
        int x = pq1.top().second.first;
        int y = pq1.top().second.second;
        
        int dist = pq1.top().first;
        pq1.pop();
        
        if(x==0 || y==0 || x==n-1 || y==m-1)
        {
            row_f = x, col_f=y;
            ans = dist;
            flag = true;
            break;
        }
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<0 || Y<0 || X>=n || Y>=m || room[X][Y]=='#' || dist+1>=monsters[X][Y])
            {
                continue;
            }
            if(human[X][Y]>dist + 1)
            {
                human[X][Y] = dist+1;
                pq1.push({human[X][Y], {X,Y}});
            }
        }
        
    }
    
    if(!flag)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        string str="";
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         cout<<human[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<row_f<<" "<<col_f<<endl;
        while(ans>0)
        {
            for(int i=0; i<4; i++)
            {
                int x = row_f + dx[i];
                int y = col_f + dy[i];
                
                if(x<0 || y<0 || x>=n || y>=m)
                {
                    continue;
                }
                if(human[x][y]==ans-1)
                {
                    str+=dir[i];
                    ans--;
                    row_f=x, col_f=y;
                    break;
                }
                
            }
        }
        
        reverse(str.begin(), str.end());
        cout<<str<<endl;
    }
    
    
}