#include <bits/stdc++.h>   //this library contains some standard used library in it
using namespace std;

int main()
{
    string str;                     
    cin>>str;
    int n=str.size();         //str.size() is used to get the size of declared string  
    int temp=0;
  
  //by using nested for loop we are checking the 
  //adjacent element of a string
    for(int i = 0; i < n-1; ++i)                
    {
        for( int j = i+1; j < n; ++j)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    
  //avoid using this nested for loop for competitive coding
  //we can used in-build function like sort(str.begin(),str.end());
  //it give the same result 

    cout<<"Sorted Strings in Lexicographical Order ::"<<str<<endl;
}
