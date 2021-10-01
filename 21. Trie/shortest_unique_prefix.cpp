/* Find shortest unique prefix to represent each word in the list.

Example:

Input: N = 4, list[] = [zebra, doll, duck, dove]
Output: {z, dol, du, dov}

Explaination: 
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

*/

#include<bits/stdc++.h>
using namespace std;

class trie{
    public: 
    int count;
    trie **arr;
    trie()
    {
        count = 0;
        arr = new trie*[26];
        for(int i=0;i<26;i++)
        {
            arr[i] = NULL;
        }
    }
};
void insert(trie *tree, string s)
{
    trie *temp = tree;
    for(int i=0;i<s.size();i++)
    {
        int a = s[i] - 'a';
        if(!temp->arr[a])
        {
            temp->arr[a] = new trie();
        }
        temp = temp->arr[a];
        temp->count++;
    }
}
string find_prefix(trie *tree , string s,string k)
{
    trie *temp = tree;
    for(int i=0;i<s.size();i++)
    {
        int a = s[i] - 'a';
        k+=(s[i]);
        temp = temp->arr[a];
        if(temp->count == 1)
        {
            break;
        }
    }
    return k;
}
vector<string> prefix(vector<string> &A) {
    trie *tree = new trie();
    for(int i=0;i<A.size();i++)
    {
        insert(tree,A[i]);
    }
    vector<string>ans;
    for(int i=0;i<A.size();i++)
    {
        string k = "";
         k = find_prefix(tree,A[i],k);
         ans.push_back(k);
    }
    return ans;
}


int main()
{
  int n;
  cin>>n;
  
  vector<string>list(n);

  for(int i=0;i<n;i++) cin>>list[i];

  vector<string>sup; //shortest unique prefix array of corresponding words

  sup = prefix(list);

  for(int i=0;i<n;i++)
    {
      cout<<sup[i]<<" ";
    }
  
}
