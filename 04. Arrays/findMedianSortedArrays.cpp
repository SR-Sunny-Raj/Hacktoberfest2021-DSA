#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> srt(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), srt.begin());
    int mid = ((srt.size() / 2) - 1);
    if (srt.size() % 2 == 1)//if srt size is odd
        return (double)srt[mid + 1];
    else//srt size is even
        return (((double)srt[mid] + srt[mid + 1]) / 2);
}
