#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter size of array"<<"\n";
    cin>>n;
    int a[n];
    cout<<"enter elements in a array"<<"\n";
    for(int i=0;i<n;i++)
     cin>>a[i];
    int k;
    cout<<"enter the kth value"<<"\n";
    cin>>k;

    priority_queue<int,vector<int>,greater<int>>minh;              // Creating min heap

    for(int i=0;i<n;i++)        
    {
        minh.push(a[i]);         // here we are pushing our array element in min heap;

        if(minh.size()>k)      // here we are checking if our heap size increases from our decided k size we will pop out the elements
                               // else continue with our pushing of arry elements
        {
            minh.pop();
        }
    }

    cout<<"Larger elements than k are:"<<"\n";

    while(minh.size()>0) // the while function here prints all the larger no present in our array of our desired K size.
    {
        
        cout<<minh.top()<<" ";
        minh.pop();
    }

}
//*********EXPLANATION************//
// we are using min heap because in min heap our maximum no is stored at bottom and minimum at top hence by checking our desired k size
// we can pop out the extra elements from heap 
// and at last we are left with the maximum elmemts presnt in the array of our required size.

//INPUT:
//{8;2;1;0;5}, K=3
//OUTPUT:
//{2;5;8}
