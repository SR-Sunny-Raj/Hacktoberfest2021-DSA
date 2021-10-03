//Nearest greater no the rigth of every no present in the array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,3,2,4}; // ans={3,4,4,-1}
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }


        else if(s.size()>0 && s.top()>arr[i])
        {
            v.push_back(s.top());
        }

        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }

        s.push(arr[i]);

    }

    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
}
