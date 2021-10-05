int Solution::solve(vector < vector < int > > & A) {
    vector < pair < int, int > > v;
    int n = A.size();
    for (int i = 0; i < n; i++)
        v.push_back({A[i][0], -A[i][1]});

    // sort the vector envelope in increasing order of heights
    sort(v.begin(), v.end());
    int dp[n];
    dp[0] = 1;

    //Find the longest increasing subsequence based on second element of v[i]
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (v[j].first < v[i].first and v[j].second > v[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp, dp + n);
}
