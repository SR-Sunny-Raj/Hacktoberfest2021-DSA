/*
problem statement:-
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

test case:- 
Input: 
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter beginWord endWord: ";
    string beginWord, endWord;
    cin>>beginWord>>endWord;

    int n;
    cout<<"Enter size of wordlist: ";
    cin>>n;
    
    vector<string> wordList(n,"");
    cout<<"Enter wordList: ";
    for(int i=0;i<n;i++)
    {
        cin>>wordList[i];
    }

    unordered_map<string, int> mp, vis;
        
    for(auto x: wordList)
        mp[x]=1;
    if(!mp[endWord]) 
    {
        cout<<"\nDestination cannit be reached\n\n";
        return 0;
    }

    queue<pair<string ,int>> Q;
    Q.push({beginWord,0});

    int ans=-1;
        
    while(!Q.empty())
    {
        auto x=Q.front();
        auto y=x.first;
        Q.pop();
            
        if(x.first==endWord)
        {
            ans=x.second+1;
            break;
        }

        for(int i=0;i<y.size();i++)
        {
            char z=y[i];
            
            for(char j='a';j<='z';j++)
            {
                if(z!=j)
                {
                    y[i]=j;
                    if(mp[y]&&!vis[y])
                    {
                        vis[y]=1;
                        Q.push({y,x.second+1});
                    }
                    y[i]=z;
                }
            }
        }
    }

    cout<<"\nOutput: "<<ans<<"\n\n";
        
        return 0;
        

    return 0;
}