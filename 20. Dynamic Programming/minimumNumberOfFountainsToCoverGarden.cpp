/*
There is a one-dimensional garden of starting at 0 and ending at n, with n + 1 fountains. In each position of the N length garden, a fountain has been installed. 
Given an array a[]such that a[i] describes the coverage limit of ith fountain. 
A fountain can cover the range from the position max(i – a[i], 1) to min(i + a[i], N). 
In beginning, all the fountains are switched off. 
The task is to find the minimum number of fountains needed to be activated such that the whole N-length garden can be covered by water.
*/
#include <iostream>
#include <vector>
using namespace std;

int minTaps(int n, vector<int>& range) 
{
    int answer = 1;
    vector<int> dp(n + 1, 0); 
    for(int i = 0; i <= n; ++i)
    {
        int left = max(i - range[i], 0);
        int right = min(i + range[i], n);
        dp[left] = max(dp[left], right);
    }
    // Now this dp[] array formed turns into jump game ii problem of leetcode
    int rightPossible = dp[0], maxRightNext = -1;
   
    for(int i = 0; i <= n; ++i)
    {
        maxRightNext = max(maxRightNext, dp[i]);

        if(i == rightPossible)
        {
            answer++;
            rightPossible = maxRightNext;
        }
        if(rightPossible == n)
        {
            return answer;
        }
    }
    return -1;
}

int main()
{
    int n, answer;
    cout << "Enter number of fountains" << endl;
    cin >> n;
    vector<int> range(n);
    cout << "Enter coverage limit of all fountains" << endl;
    for(int i = 0; i < n; ++i)
    {
        cin >> range[i];
    }
    answer = minTaps(n - 1, range);
    cout << "Minimum number of fountains needed is " << answer << endl;
}