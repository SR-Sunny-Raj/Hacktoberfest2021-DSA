#include <bits/stdc++.h>
using namespace std;

string AlienDictionary(string ar[], int n, int k) {
	// Graph for char
	map<int, vector<int>> m;
	string ans = "";

	for (int i = 0; i < n - 1; ++i) {
		int l = 0, r = 0;
		bool flag = 0;
		while (l < ar[i].length() && r < ar[i + 1].length()) {
			if (ar[i][l] != ar[i + 1][r]) {
				m[ar[i][l] - 'a'].push_back(ar[i + 1][r] - 'a');
				flag = 1;
				break;
			}
			l++, r++;
		}
	}

	for (auto x : m) {
		cout << char(x.first + 'a') << "-> ";
		for (auto y : x.second)cout << char(y + 'a') << " ";
		cout << endl;
	}

	// topological sorting
	int indegree[k] = {0};

	for (auto x : m) {
		for (auto y : x.second)indegree[y]++;
	}

	// BFS
	queue<int>q;
	for (int i = 0; i < k; i++)if (indegree[i] == 0)q.push(i);

	while (!q.empty()) {
		int node = q.front(); q.pop();
		ans += char(node + 'a');
		for (auto adj : m[node]) {
			indegree[adj]--;
			if (indegree[adj] == 0)q.push(adj);
		}
	}

	return ans;

}

int main() {

	string arr[] = {"baa", "abcd", "abca", "cab", "cad"};
	int n = 5, k = 4;

	cout << AlienDictionary(arr, n, k) << '\n';

	return 0;
}