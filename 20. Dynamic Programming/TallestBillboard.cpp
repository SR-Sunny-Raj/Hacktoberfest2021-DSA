#include<bits/stdc++.h>
using namespace std;

int dp[25][10050];

int rec(int n, vector<int> &rods, int s1, int s2) {
    if(n < 0) {
        if(s1 == s2) return 0;
        return INT_MIN;
    }
            
    if(dp[n][s1 - s2 + 5050] != -1) return dp[n][s1 - s2 + 5050];
    
    int x = rec(n - 1, rods, s1 + rods[n], s2) + rods[n];
    int y = rec(n - 1, rods, s1, s2 + rods[n]);
    int z = rec(n - 1, rods, s1, s2);
    
    return dp[n][s1 - s2 + 5050] = max({ x, y, z });
}

int tallestBillboard(vector<int>& rods) {
    memset(dp, -1, sizeof(dp));
    return rec(rods.size() - 1, rods, 0, 0);
}

int main() {
    vector<int> rods = {1,2,3,4,5,6};
    cout << tallestBillboard(rods)
    return 0;
}