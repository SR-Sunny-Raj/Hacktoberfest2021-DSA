// Problem Link: https://leetcode.com/problems/daily-temperatures/

// Solution:

#include"bits/stdc++.h"
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>>s;
    s.push({temperatures[0], 0});
    vector<int>ans(temperatures.size(), 0);
    for (int i = 1; i < temperatures.size(); i++) {
        while (!s.empty() and s.top().first < temperatures[i]) {
            ans[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({temperatures[i], i});
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int>temperatures;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        temperatures.push_back(curr);
    }
    vector<int>ans = dailyTemperatures(temperatures);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}