
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;

    string str;

    for (int i = 0; i < n; i++)
    {

        int flag;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            flag = 0;
            for (int k = 0; k < s.size(); k++)
            {
                if (str[j] == s[k])
                {
                    flag = 1;
                    break;
                }

                
            }

            if (flag == 0)
            {
                break;
            }
        }

        if (flag == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}
