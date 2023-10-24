// Problem Link: https://www.codechef.com/JAN21C/problems/BILLRD

#include <iostream>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t >= 1)
    {
        int n = 0, c = 0, h = 0, k = 0;
        cin >> n >> c >> h >> k;

        if (h == k)
        {
            cout << n << " " << n << "\n";
        }
        else if ((n - k) > (n - h))
        {
            int hit_wall = c % 4;
            int x=0,y=0;
            switch (hit_wall)
            {
            case 1:
                x=n;
                y=n-h+k;
                break;
            case 2:
                x=n-h+k;
                y=n;
                break;
            case 3:
                x=0;
                y=h-k;
                break;
            case 0:
                x=h-k;
                y=0;
                break;
            }

            cout << x << " " << y << "\n";
        }
        else
        {
            int hit_wall = c%4;
            int x=0,y=0;
            switch (hit_wall)
            {
            case 1:
                x=n-k+h;
                y=n;
                break;
            case 2:
                x=n;
                y=n-k+h;
                break;
            case 3:
                x=k-h;
                y=0;
                break;
            case 0:
                x=0;
                y=k-h;
                break;
            }

            cout << x << " " << y << "\n";
        }

        t--;
    }

    return 0;
}