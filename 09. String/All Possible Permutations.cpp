/* Given a String s, print all the possible permutations of that string ..For e.g. the string is 
abc ..So the required permutations are abc, acb, bac, bca, cab, cba.. */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	sort(s.begin(),s.end());
	
    do{
        cout<<s<<"\n";
    }while(next_permutation(s.begin(),s.end()));
}
    //next_permutation is included in the #include<algorithm> library
    //It returns ‘true’ if the function could rearrange the object as
    //a lexicographically
    //greater permutation. Otherwise, the function returns ‘false’.
    //Changes the string s to newest permutation string