 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define pb push_back
 #define vi vector<int>
 #define vl vector<ll>
 #define pii pair<int,int>
 #define pll pair<ll,ll>

  int gcd(int a,int b)
 {
     if(b==0){return a;}
     else {return gcd(b,b%a);}
 }
 int main()
 {
 ios_base::sync_with_stdio(false);
 /* cin.tie(NULL);
 cout.tie(NULL); */
 
  
     cout<<"Enter two num of which gcd you want to find\n";
     int x,y;
     cin>>x>>y;
     cout<<gcd(x,y);
  
 return 0;
 }
