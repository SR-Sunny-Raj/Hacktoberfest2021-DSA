// queries to find max sum subarray from l to r.

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long int n, q, a[N];

struct node{
    long long ans, sum, left, right;
};

node seg_tree[N];

void build(int vertex, int l, int r){
    if(l > r) return;
    if(l == r){
        // 1 --> max sub sum, 2--> max pre sum, 3 --> max suf sum, 4 --> sum
        seg_tree[vertex].ans = a[l];
        seg_tree[vertex].left = a[l];
        seg_tree[vertex].right = a[l];
        seg_tree[vertex].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * vertex, l, mid);
    build(2 * vertex + 1, mid + 1, r); 
    seg_tree[vertex].ans = max({seg_tree[2*vertex].ans, seg_tree[2 * vertex + 1].ans, seg_tree[2 * vertex].right + seg_tree[2 * vertex + 1].left});
    seg_tree[vertex].left = max({seg_tree[2 * vertex].left, seg_tree[2 * vertex].sum + seg_tree[2 * vertex + 1].left});
    seg_tree[vertex].right = max({seg_tree[2 * vertex + 1].right, seg_tree[2 * vertex + 1].sum  + seg_tree[2 * vertex].right});
    seg_tree[vertex].sum = seg_tree[2 * vertex].sum + seg_tree[2 * vertex + 1].sum;
}
 
void upd(int vertex, int l, int r, int pos, long long int val){
    if(l > pos or r < pos) return;
    if(l == r){
        seg_tree[vertex].ans = val;
        seg_tree[vertex].left = val;
        seg_tree[vertex].right = val;
        seg_tree[vertex].sum = val;
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * vertex, l, mid, pos, val);
    upd(2 * vertex + 1, mid + 1, r, pos, val);
    seg_tree[vertex].ans = max({seg_tree[2*vertex].ans, seg_tree[2 * vertex + 1].ans, seg_tree[2 * vertex].right + seg_tree[2 * vertex + 1].left});
    seg_tree[vertex].left = max({seg_tree[2 * vertex].left, seg_tree[2 * vertex].sum + seg_tree[2 * vertex + 1].left});
    seg_tree[vertex].right = max({seg_tree[2 * vertex + 1].right, seg_tree[2 * vertex + 1].sum  + seg_tree[2 * vertex].right});
    seg_tree[vertex].sum = seg_tree[2 * vertex].sum + seg_tree[2 * vertex + 1].sum;
}

node empty_Node(){
    node ret;
    ret.left = ret.right = ret.sum = ret.ans = INT_MIN;
    return ret;
}

node combine(node a, node b){
    node res;
    res.sum = a.sum + b.sum;
    res.left = max({a.left, a.sum + b.left});
    res.right = max({b.right, b.sum + a.right});
    res.ans = max({b.ans, a.ans, a.right  + b.left});
    return res;
}

node answer(int vertex, int l, int r, int str, int endd){
    if(l > endd or r < str) return empty_Node();
    if(l >= str and r <= endd)
        return seg_tree[vertex];
    int mid = (l + r) / 2;
    node cur = answer(2 * vertex, l, mid, str, endd);
    node cur1 = answer(2 * vertex + 1, mid + 1, r, str, endd);
    return combine(cur, cur1);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    // cout << seg_tree.ans.ans << '\n';
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << answer(1, 1, n, l, r).ans << '\n';
    }
}
 
int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}    
