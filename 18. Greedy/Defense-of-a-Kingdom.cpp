#include<bits/stdc++.h>
using namespace std;
int main(){
  //r is no. of rows
  //c is no. of columns
  //t is no. of towers
    int r, c, t;
    cin>>r>>c>>t;
  //v stores vertical position of ith tower
  //h stores horizontal position of ith tower
  //we also store start and end of row in h and col in c respectively
    vector<int>v(t);
    vector<int>h(t);
    v.push_back(0);
    h.push_back(0);
    for(int i=0;i<t;i++){
        int a, b;
        cin>>a>>b;
        h.push_back(a);
        v.push_back(b);
    }
    h.push_back(r);
    v.push_back(c);
    sort(v.begin(),v.end());
    sort(h.begin(),h.end());
  //ansv store max possible vertical dist between two towers
  //ansh store max possible horizontal dist between two towers
    int ansv=0, ansh=0;
    for(int i=1;i<v.size();i++){
        ansv=max(ansv,(v[i]-v[i-1]-1));
        ansh=max(ansh,(h[i]-h[i-1]-1));
    }
  //final ans will be area of rectangle with ansv and ansh as dimensions
    cout<<ansh*ansv;
    return 0;
}
