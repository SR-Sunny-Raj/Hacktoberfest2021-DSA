/*
Problem link : https://leetcode.com/problems/the-skyline-problem/
*/

struct range {
  int L, R, y = 0;
};

class Solution {
  int N;
  vector<range> tree;

  // Set the ranges of the non-leaf nodes using the ranges of their children
  void pushup(int i) {
    if (i >= N)
      return;
    pushup(i << 1);
    pushup(i << 1 | 1);
    tree[i].L = tree[i << 1].L;
    tree[i].R = tree[i << 1 | 1].R;
  }

  // Insert a new building into the segment tree
  void insert(int i, range building) {
    // the building is completely covered by the range of tree[i]
    if (tree[i].y >= building.y)
      return;

    // ensure the building at least overlaps the range of tree[i]
    if (building.L < tree[i].R && tree[i].L < building.R) {
      // check if the building completely covers the range of tree[i]
      if (building.L <= tree[i].L && tree[i].R <= building.R) {
        tree[i].y = std::max(tree[i].y, building.y);
      } else {
        assert(i < N); // if this doesn't hold here we messed up
        insert(i << 1, building);
        insert(i << 1 | 1, building);
      }
    }
  }

  // Push heights in aggregator nodes down to leaf nodes
  void pushdown(int i) {
    // if this updates tree[i].y, thats means the range of tree[i] was
    // completely covered up by the range of tree[i >> 1], like so:
    //  __________
    //  |____    |
    //  | i |    |
    tree[i].y = max(tree[i].y, tree[i >> 1].y);
    if (i < N) {
      pushdown(i << 1);
      pushdown(i << 1 | 1);
    }
  }

public:
  vector<vector<int>> getSkyline(const vector<vector<int>> &buildings) {
    if (buildings.empty())
      return {};

    // find the set of x-coordinate boundaries delimiting the buildings
    vector<int> boundary;
    for (const auto &building : buildings) {
      boundary.push_back(building[0]);
      boundary.push_back(building[1]);
    }
    sort(boundary.begin(), boundary.end());
    boundary.erase(unique(boundary.begin(), boundary.end()), boundary.end());

    // the boundaries are split into N indivisible ranges
    N = boundary.size() - 1;
    tree.assign(2 * N, {}); // reset from previous run

    // fill the leaves of the tree with the indivisible ranges
    for (int i = 0; i < N; ++i) {
      tree[i + N].L = boundary[i];
      tree[i + N].R = boundary[i + 1];
    }
    // now the leaves are aligned with the array and not the tree,
    // to align them with the tree we need to rotate tree[N,2N)
    auto nbegin = tree.begin() + N; // tree[N]
    auto nend = tree.end();         // tree[2N]
    int P = 1;
    while (P < N)
      P <<= 1;

    rotate(nbegin, nbegin + (2 * N - P), nend); // align leaves with tree
    pushup(1);
    // now insert each building into the tree
    for (const auto &building : buildings) {
      insert(1, {building[0], building[1], building[2]});
    }
    pushdown(1);
    rotate(nbegin, nbegin + (P - N), nend); // align leaves with array
    // now the leaves are aligned with the array again, so nbegin..nend
    // contains the indivisible ranges in order.

    // now build the skyline, left to right, knowing tree[i].y contains
    // the largest height covering the range [tree[i].L, tree[i].R)
    vector<vector<int>> skyline;
    auto left = nbegin, right = nbegin + 1;

    skyline.push_back({left->L, left->y});
    for (; right != nend; ++left, ++right) {
      if (left->y != right->y) {
        skyline.push_back({right->L, right->y});
      }
    }
    skyline.push_back({left->R, 0});

    return skyline;
  }
};

