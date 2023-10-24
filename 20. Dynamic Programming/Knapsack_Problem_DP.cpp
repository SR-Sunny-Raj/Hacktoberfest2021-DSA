#include<iostream>
using namespace std;
int main()
{
    int P[]={0,1,2,5};
    int Wt[]={0,2,3,4};
    int m=5,n=3;
    int K[4][6];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
           if(i==0 || j==0)
                K[i][j]=0;
           else if(Wt[i]<=j)
                K[i][j]=max(K[i-1][j],K[i-1][j-Wt[i]]+P[i]);
           else
                K[i][j]=K[i-1][j];
        }
    }
    cout<<"Weight: ";
    for(int i=1;i<=n;i++)
    {
        cout<<Wt[i]<<" ";
    }
    cout<<"\nProfit: ";
    for(int i=1;i<=n;i++)
    {
        cout<<P[i]<<" ";
    }
    cout<<"\n\nMAX Profit: "<<K[n][m];
    return 0;
}
