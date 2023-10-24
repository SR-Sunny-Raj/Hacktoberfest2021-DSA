#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    typedef struct TrieNode
    {
        TrieNode *child[26] = {NULL};
        bool isEnd = false;
    } TrieNode;
    string result = "";

    void insert(TrieNode *head, string &s)
    {
        for (auto &x : s)
        {
            int pos = x - 'a';
            if (!head->child[pos])
            {
                TrieNode *temp = new TrieNode;
                head->child[pos] = temp;
            }
            head = head->child[pos];
        }
        head->isEnd = true;
    }

    void DFS(TrieNode *head, int lvl, string &curr)
    {
        if (!head->isEnd)
            return;
        if (result.length() < lvl)
            result = curr;
        for (int i = 0; i < 26; i++)
        {
            if (head->child[i])
            {
                char temp = 'a' + i;
                curr += temp;
                DFS(head->child[i], lvl + 1, curr);
                curr.pop_back();
            }
        }
    }

    string longestWord(vector<string> &words)
    {
        TrieNode *head = new TrieNode;
        head->isEnd = true;
        for (auto &word : words)
            insert(head, word);
        string curr = "";
        DFS(head, 0, curr);
        return result;
    }
};

int main()
{
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Solution s1;
    cout << s1.longestWord(words);
    return 0;
}