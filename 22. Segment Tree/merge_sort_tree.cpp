/*
Merge sort tree

Overview:
Merge sort tree is a Segment tree, each node of which contains a sorted set/vector of every element in its range.
It's build it in a bottom-up manner. To build the parent nodes, we merge 2 sets/vectors of the children the same as we do in the merge-sort algorithm in O(number of elements), 
hence the name Merge-sort tree.

Prerequisite: 
Recursion, Segment tree

Use cases:
- Find the number of elements greater / smaller than a given number x in a given range [l...r]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MergeSortTree {
    
private:
    vector<vector<int>> tree;
    vector<int> arr;
    
public:
    
    MergeSortTree(int n, vector<int> &a) {
        tree = vector<vector<int>> (4 * n);
        arr = a;
    }
    
    /*
    si: segment index
    ss: segment start
    se: segment end
    */
    void build_tree(int si, int ss, int se) {
        if(ss > se) {
            return;
        }
        
        if(ss == se) {
            tree[si].push_back(arr[si]);
            return;
        }
        
        int mid = ss + (se - ss) / 2;
        
        // build the left half
        build_tree(2 * si + 1, ss, mid);
        
        // build the right half
        build_tree(2 * si + 2, mid + 1, se);
        
        // merge the two halfs at the end
        merge(tree[2 * si + 1].begin(), tree[2 * si + 1].end(), tree[2 * si + 2].begin(), tree[2 * si + 2].end(), back_inserter(tree[si]));
    }
    
    /*
    si: segment index
    ss: segment start
    se: segment end
    qs: query start
    qe: query end
    x: give value
    */
    int query(int si, int ss, int se, int qs, int qe, int x) {
        
        // segment range is out of query range
        if(qe < ss || se < qs) {
            return 0;
        }
        
        // query range lies inside the segment range
        if(ss <= qs && qe <= se) {
            // binary search over the sorted segment range.
            // count of elements which are >= (greater than or equal to) x.
            return upper_bound(tree[si].begin(), tree[si].end(), x) - tree[si].begin(); 
        }
        
        int mid = ss + (se - se) / 2;
        
        // result from left segment
        int left = query(2 * si + 1, ss, mid, qs, qe, x);
        
        // result from right segment.
        int right = query(2 * si + 2, mid + 1, se, qs, qe, x);
        
        // total result for the current range [ss...se]
        return left + right;
    }  
};