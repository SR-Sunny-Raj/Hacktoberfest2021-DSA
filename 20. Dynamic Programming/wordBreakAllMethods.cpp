
#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    node *children[26];
    bool isEOW;
} node;
node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    for (int i = 0; i < 26; i++)
        newNode->children[i] = NULL;

    newNode->isEOW = false;
    return newNode;
}
void insertNode(node *root, string key)
{
    node *cur = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!cur->children[index])
            cur->children[index] = createNode();
        cur = cur->children[index];
    }
    cur->isEOW = true;
}
bool searchKey(node *root, string key)
{
    node *cur = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!cur->children[index])
            return false;
        cur = cur->children[index];
    }
    return cur && cur->isEOW;
}
bool dictionaryContains(vector<string> dictionary, string str)
{
    for (int i = 0; i < dictionary.size(); i++)
    {
        if (dictionary[i].compare(str) == 0)
            return true;
    }
    return false;
}
bool wordBreakRecursive(vector<string> dictionary, string str)
{
    int size = str.size();

    if (size == 0)
        return true;
    for (int i = 1; i <= size; i++)
    {
        if (dictionaryContains(dictionary, str.substr(0, i)) && wordBreakRecursive(dictionary, str.substr(i, size - i)))
            return true;
    }
    return false;
}
bool wordBreakDp4(vector<string> dictionary, string str)
{
    int size = str.size();
    vector<int> dp(size + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < size; i++)
    {
        if (dp[i])
        {
            for (auto w : dictionary)
            {
                if (str.substr(i, w.size()) == w)
                    dp[i + w.size()] = 1;
            }
        }
    }
    return dp[size];
}
bool wordBreakDp2(vector<string> dictionary, string str)
{
    int size = str.size();
    vector<bool> dp(size + 1, 0);
    vector<int> matchedIndex;
    matchedIndex.push_back(-1);
    for (int i = 0; i < size; i++)
    {
        int f = 0;
        int msize = matchedIndex.size();
        for (int j = msize - 1; j >= 0; j--)
        {
            string sub = str.substr(matchedIndex[j] + 1, i - matchedIndex[j]);
            if (dictionaryContains(dictionary, sub))
            {
                f = 1;
                break;
            }
        }
        if (f)
        {
            dp[i] = 1;
            matchedIndex.push_back(i);
        }
    }
    return dp[size - 1];
}
bool wordBreakDp3(node *root, string str)
{
    int size = str.size();
    vector<bool> dp(size + 1, 0);
    vector<int> matchedIndex;
    matchedIndex.push_back(-1);
    for (int i = 0; i < size; i++)
    {
        int f = 0;
        int msize = matchedIndex.size();
        for (int j = msize - 1; j >= 0; j--)
        {
            string sub = str.substr(matchedIndex[j] + 1, i - matchedIndex[j]);
            if (searchKey(root, sub))
            {
                f = 1;
                break;
            }
        }
        if (f)
        {
            dp[i] = 1;
            matchedIndex.push_back(i);
        }
    }
    return dp[size - 1];
}
bool wordBreakDp(vector<string> dictionary, string str)
{
    int size = str.size();
    int j;
    if (size == 0)
        return true;
    vector<int> dp(size + 1, 0);
    for (int i = 1; i <= size; i++)
    {
        if (!dp[i] && dictionaryContains(dictionary, str.substr(0, i)))
            dp[i] = 1;
        if (dp[i])
        {
            if (i == size)
                return true;
            for (j = i + 1; j <= size; j++)
            {
                if (!dp[j] && dictionaryContains(dictionary, str.substr(i, j - i)))
                    dp[j] = 1;
            }
            if (dp[i] && size == j)
                return true;
        }
    }
    return false;
}

int main()
{
    string str;
    cout << "Enter string" << endl;
    cin >> str;

    vector<string> dictionary = {"mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"};
    //1
    if (wordBreakRecursive(dictionary, str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    //2
    if (wordBreakDp(dictionary, str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    //3
    if (wordBreakDp2(dictionary, str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    //3
    node *root = createNode();
    for (int i = 0; i < dictionary.size(); i++)
        insertNode(root, dictionary[i]);
    if (wordBreakDp3(root, str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    //4
    if (wordBreakDp4(dictionary, str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
/*
- wordBreak: https://www.geeksforgeeks.org/word-break-problem-dp-32/
  - methods
    - recursive: Tc:(2^s \*n ), Sc:(n^2): recursive calls. s=length of string,n=length of dictionary
    - Dp: Tc:O(s^2 \* n), Sc: o(s)
    - Dp2: Tc:O(s\*n) Sc:O(s)
    - Dp3: similar to Dp2, for checking whether the string present in dictionary use trie.
    - Dp4: Tc: O(s\*n\*maxWordLengthOfDict)
*/