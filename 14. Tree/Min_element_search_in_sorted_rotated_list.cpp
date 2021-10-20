#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

int main()
{
    vector<int> nums{5, 6, 1, 2};

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (nums[mid] < nums[r])
            r = mid;

        else
            l = mid + 1;
    }

    cout << nums[l] << endl;

    return 0;
}