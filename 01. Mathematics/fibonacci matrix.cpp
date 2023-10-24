#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
void mul(int a[2][2] , int b[2][2] )
{
    int i, j, k;
    int res[2][2];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 2; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    a[0][0] = res[0][0];
    a[0][1] = res[0][1];
    a[1][0] = res[1][0];
    a[1][1] = res[1][1];

}
void matpow(int p[2][2] , int b ,int ans[2][2])
{

    while(b>0)
    {
        if(b&1)
            mul(ans,p);
        mul(p,p);
        b >>=1;
    }
}
int32_t main()
{
    IOS;
    int ans[2][2];
    ans[0][0] = 1;
    ans[0][1] = 1;
    ans[1][0] = 1;
    ans[1][1] = 1;
    int n;
    cin>>n;
    int p[2][2];
    p[0][0] = 1;
    p[0][1] = 1;
    p[1][0] = 1;
    p[1][1] = 0;
    matpow(p,n-2,ans);
    cout<<ans[0][0];





    return 0;
}
