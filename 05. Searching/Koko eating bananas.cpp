// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
// The guards have gone and will come back in h hours. Koko can decide her bananas-per-hour eating speed of k.
// Each hour, she chooses some pile of bananas and eats k bananas from that pile.
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Input: piles = [3,6,7,11], h = 8
// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int l = 1;
        int r = *max_element(a.begin(), a.end());
        // Binary Search algorithm
        while(l<=r) {
            int mid = (l+r)/2;
            int total = 0;
            for(int i=0; i<a.size(); i++) {
                total += (a[i] + mid - 1)/mid;
            }
            total <= h ? r = mid-1 : l = mid+1;
        }
        return l;
    }
};