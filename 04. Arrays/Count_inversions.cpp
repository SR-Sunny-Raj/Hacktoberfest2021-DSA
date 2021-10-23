#include <bits/stdc++.h>
using namespace std;
long long int merger(vector<long long> &v, int si, int ei, int mid) {
    int ls = si, le = mid;
    int rs = mid + 1, re = ei;
    long long temp[ei - si + 1];
    int k = 0;
    long long cnt = 0;
    while (ls <= le && rs <= re) {
        if (v[ls] > v[rs]) {
            temp[k++] = v[rs++];
            cnt += le - ls + 1;
        } else if (v[ls] <= v[rs]) {
            temp[k++] = v[ls++];
        }
    }
    while (ls <= le) {
        temp[k++] = v[ls++];
    }
    while (rs <= re) {
        temp[k++] = v[rs++];
    }
    k = 0;
    for (int i = si; i < ei + 1; i++) {
        v[i] = temp[k++];
    }
    return cnt;
}
long long int helper(vector<long long> &v, int si, int ei) {
    if (si >= ei) {
        return 0;
    }
    int mid = (si + ei) / 2;
    long long left = helper(v, si, mid);
    long long right = helper(v, mid + 1, ei);
    return (left + right + merger(v, si, ei, mid));
}
long long int inversionCount(vector<long long> arr, long long N) {
    // Your Code Here
    vector<long long> v;
    for (int i = 0; i < N; i++) {
        v.push_back(arr[i]);
    }
    return helper(v, 0, N - 1);
}
int main() {
    long long n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    long long int res = inversionCount(arr, n);
    cout << res << endl;
}