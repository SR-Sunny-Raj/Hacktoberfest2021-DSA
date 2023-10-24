#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x)
    {
        long long low = 1;
        long long high = x;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x)
            {
                high = mid;
                break;
            }
            else if (mid * mid > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};
