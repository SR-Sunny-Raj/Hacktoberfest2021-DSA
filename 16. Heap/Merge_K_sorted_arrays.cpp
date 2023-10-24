#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<int,pi> pv;
#define mk make_pair

int main()
{
     int n,k;
     cin>>k>>n;

     vector<vector<int>> a(k);
     int b[n*k]={0},l=0;
     int c[n];
     for(int i=0;i<k;i++)
         for(int j=0;j<n;j++)
         {
               int d;
               cin>>d;
             a[i].push_back(d);
        }
  
     priority_queue<pi,vector<pi>,greater<pi>> pq;
     
     for(int i=0;i<k;i++)
     {
           int d  = a[i][0];
         pq.push(mk(d,i));
         a[i].erase(a[i].begin());
     }
  
     int m;
     pair<int,int> d;
  
     while((pq.top()).second != -1){
          d = pq.top();
          b[l++] = d.first;           // smallest element
          m = d.second;           
          pq.pop();
          if(a[m].size()==0)
          pq.push(mk(INT_MAX,-1));
          else
          {
                int e = a[m][0];
                pq.push(mk(e,m));
                a[m].erase(a[m].begin());
          }
     }
  
     for(int i=0;i<n*k;i++)
     cout<<b[i]<<" ";
}
