//C++ STL program to reverse vector elements 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a;
    vector<int> v1;
    for(int i=0;i<5;i++)
    {
    cin>>a;
    v1.push_back(a);
    }

    //printing elements
    cout << "before reversing vector elements..." << endl;
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    //reversing vector's all elements
    reverse(v1.begin(), v1.end());

    //printing elements
    cout << "after reversing vector elements..." << endl;
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    return 0;
}
