//Problem link : https://cses.fi/problemset/result/2892036/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
	
vector<ll> ad[100005];
ll visited[100005] = {0};
ll parent[100005];
 
bool dfs(ll i, ll prev){
	visited[i] = 1;
	parent[i] = prev;
	for(auto ne: ad[i]){
		if(!visited[ne]){
			dfs(ne, i);
		}else if(ne != prev){
			vector<ll> c;
			ll curr = i;
			c.push_back(curr);
			while(parent[curr]!=ne){
				curr = parent[curr];
				c.push_back(curr);
			}
			c.push_back(ne); c.push_back(i);
			cout << c.size() << '\n';
			for(auto k: c){
				cout << k << " ";
			}
			exit(0);
		}
	}
	return false;
}
 
int main() {
	ll n,m,a,b;
	memset(parent, -1, sizeof(parent));
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> a >> b;
		ad[a].push_back(b);
		ad[b].push_back(a);	
	}
	for(ll i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, -1);
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
