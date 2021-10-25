/*
Given an array of strings words and an integer k, return the k most frequent
strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words
with the same frequency by their lexicographical order.



Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k
= 4 Output: ["the","is","sunny","day"] Explanation: "the", "is", "sunny" and
"day" are the four most frequent words, with the number of occurrence being 4,
3, 2 and 1 respectively.*/

// Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {

    unordered_map<string, int> umap;
    for (int i = 0; i < words.size(); i++) {
      umap[words[i]]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
    for (auto x : umap) {
      pq.push({x.second, x.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      // res.insert(res.begin(), pq.top().second);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }

private:
  struct MyComp {
    // Comparator
    // cleaned up a bit
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) {
      if (p1.first == p2.first) {
        return p1.second < p2.second;
      }
      return p1.first > p2.first;
    }
  };
};
// driver function added
int main() {
  int count = 3; // top k
  vector<vector<string>> tests = {
      {"i", "love", "leetcode", "i", "hello", "leetcode", "coding", "a"},
      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
  };
  Solution S;
  for (auto test : tests) {
    vector<string> sol = S.topKFrequent(test, count);
    for (auto i : sol)
      cout << i << " ";
    cout << endl;
  }
}