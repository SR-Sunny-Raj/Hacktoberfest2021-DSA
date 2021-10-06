// A complex number can be represented as a string on the form "real+imaginaryi" where:

// real is the real part and is an integer in the range [-100, 100].
// imaginary is the imaginary part and is an integer in the range [-100, 100].
// i2 == -1.
// Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

//  code:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        return multiply(number(num1),number(num2));

    }
    pair<int,int> number(string s)
    {
        int i=0;
        while(s[i]!='+')
            i++;
        return make_pair(stoi(s),stoi(s.substr(++i)));
    }
    string multiply(pair<int,int> a ,pair<int,int> b)
    {
        int c= a.first*b.first - a.second*b.second;
        int d= a.second*b.first + a.first*b.second;
        string ss= to_string(c)+"+"+to_string(d)+"i";
        return ss;
    }
};

int main()
{
  string num1,num2;
  cout<<"Enter 2nd complex no. ";
  getline(cin,num1);
  cout<<"\nEnter 2nd complex no. ";
  getline(cin,num2);
  cout<<endl;

  Solution ans;
  cout<<ans.complexNumberMultiply(num1,num2)<<endl;
  return 0;
}