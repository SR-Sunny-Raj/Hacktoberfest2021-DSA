#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define deb(x)          cout << #x << "=" << x << endl
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void buildTree(vi &arr, vi &tree, int s, int e, int idx) {
	if (s == e) {
		tree[idx] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(arr, tree, s, mid, 2 * idx);
	buildTree(arr, tree, mid + 1, e, 2 * idx + 1);
	tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	return;
}

int Query(vi &tree, int s, int e, int qs, int qe, int idx) {
	if (e < qs || s > qe) {
		return 0;
	}

	if (s >= qs and e <= qe) {
		return tree[idx];
	}

	int mid = (s + e) / 2;
	int left  = Query(tree, s, mid, qs, qe, 2 * idx);
	int right = Query(tree, mid + 1, e, qs, qe, 2 * idx + 1);

	return (left + right);
}

void updateNode(vi &tree, int s, int e, int idx, int i, int change) {
	if (i < s || i > e) {
		return;
	}

	if (s == e) {
		tree[idx] += change;
		return;
	}
	int mid = (s + e) / 2;
	updateNode(tree, s, mid, 2 * idx, i, change);
	updateNode(tree, mid + 1, e, 2 * idx + 1, i, change);
	tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	return;

}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vi arr = {1, 3, 2, 5, 6, 4};
	int n = arr.size();

	vi tree(4 * n + 1);
	buildTree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	updateNode(tree, 0, n - 1, 1, 3, 10);

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << Query(tree, 0, n - 1, l, r, 1) << "\n";
	}
}

int32_t main()
{
	clock_t begin = clock();
	c_p_c();
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}