#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m1[][2]={{2,3},{4,2}};
    int m2[][2]={{1,2},{2,3}};
    int m[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            m[i][j]=0;
            for(int k=0;k<2;k++)
            {
                m[i][j]+=m1[i][k]+m2[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}
