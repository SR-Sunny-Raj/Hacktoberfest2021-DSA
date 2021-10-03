//#include <iostream>
//#include <vector>
#include<stdc++.h>
using namespace std;

#define p pair<int,int>
#define v vector<p>
#define profit first
#define weight second

bool compare(p p1, p p2)
{
    double ratio1,ratio2;
    ratio1=(double)p1.profit/p1.weight;
    ratio2=(double)p2.profit/p2.weight;
    return ratio1>ratio2;
}
float knapsack(v veg, int capacity, int n)
{
    float total=0;
    for(int i=0; i<n; i++)
    {
        if(capacity>=veg[i].weight)
        {
            total+=veg[i].profit;
            capacity-=veg[i].weight;
            continue;
        }
        double valuePerWt;
        valuePerWt=(double)veg[i].profit/veg[i].weight;
        total+=valuePerWt*capacity;
        capacity=0;
        break;
    }
    return total;
}
int main()
{
    int n;
    cin>>n;
    v veg(n);
    for(int i=0;i<n;i++)
    {
        cin>>veg[i].weight;
    }
    for(int i=0;i<n;i++)
    {
        cin>>veg[i].profit;
    }
    int capacity;
    cin>>capacity;
    sort(veg.begin(),veg.end(),compare);
    float total;
    total=knapsack(veg,capacity, n);
    cout<<total;
    return 0;
}