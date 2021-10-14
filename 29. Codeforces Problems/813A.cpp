#include<iostream>
#include<algorithm>
using namespace std;
struct tera
{
    int st, end;
}a[1005];
int main()
{
    int n,m;
    while (cin >> n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i].st >> a[i].end;
        }
        if (sum > a[m - 1].end)
            cout << "-1"<<endl;
        else
        {
            for (int i = 0; i < m; i++)
            {
                if (sum < a[i].st)
                {
                    cout << a[i].st << endl;
                    break;
                }
                if (sum >= a[i].st&&sum <= a[i].end)
                {
                    cout << sum << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
