/* Codeforces Question - Turn the Rectangles 

    Difficulty Rating - 1000
    Tags -  Greedy , Sortings
    Time Taken to Execute - 77 ms
    
    Link to the Question - https://codeforces.com/contest/1008/problem/B
    
    
    This Code is Contributed by - Rakshit Pandey (Github Username ----> Master-Helix)
    
    */
    
    
 /*  DESCRIPTION Of the Question:-
     There are n rectangles in a row. You can either turn each rectangle by 90 degrees or leave it as it is. If you turn a rectangle, its width will be height, and its height will be width. Notice that you can turn any number of rectangles, you also can turn all or none of them. You can not change the order of the rectangles.

Find out if there is a way to make the rectangles go in order of non-ascending height. In other words, after all the turns, a height of every rectangle has to be not greater than the height of the previous rectangle (if it is such).

Input
The first line contains a single integer n (1≤n≤105) — the number of rectangles.

Each of the next n lines contains two integers wi and hi (1≤wi,hi≤109) — the width and the height of the i-th rectangle.

Output
Print "YES" (without quotes) if there is a way to make the rectangles go in order of non-ascending height, otherwise print "NO".

You can print each letter in any case (upper or lower).



Input:
3
3 4
4 6
3 5


Output:
YES



Input:
2
3 4
5 5

Output:
NO


------------------------------------------------------------------------------------ */
 
 //SOLUTION    
    
#include <bits/stdc++.h>
using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long 
#define l long long



// RAKSHIT
int main()
{
  
  fast();
  ll n;
  cin>>n;
  vector<pair<ll,ll>>v;
  for(int i=0;i<n;i++)
  {
    ll w1,h1;
    cin>>w1>>h1;
    v.push_back(make_pair(w1,h1));
  }
  
  ll maxi=max(v[0].first,v[0].second);
  
  int flag=0;
  for(int i=1;i<n;i++)
  {
    ll val=min(v[i].first,v[i].second);
    ll val2=max(v[i].first,v[i].second);
    if(val>maxi)
    {
      flag=1;
      break;
    }
    else
    {
      if(val2<=maxi)
      {
        maxi=val2;
      }
      else
      {
        maxi=val;
      }
    }
  }
  
  if(flag==1)
  {
    cout<<"NO";
  }
  else
  {
    cout<<"YES";
  }
}
    
 
