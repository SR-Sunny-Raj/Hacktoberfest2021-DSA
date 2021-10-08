#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t, n, mx, b, c, x;
    
    scanf("%d", &t);
    
    while (t--)
    {
        mx = INT_MIN;
        
        unordered_set<int> s;
        
        scanf("%d", &n);
        
        int a[n];
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > mx)
                mx = a[i];
        }
        
        s.insert(0);
        
        if(mx >= 1)
            s.insert(1);
            
        c = 0;
        b = 1;
        
        while(c + b <= mx)
        {
            x = c + b;
            s.insert(x);
            c = b;
            b = x;
        }
        
    for(int i = 0; i < n; i++)
    {
        if(s.find(a[i]) != s.end())
            printf("%d ", a[i]);
    }
    printf("\n");
       
    }

    return 0;
}