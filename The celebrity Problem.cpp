#include <bits/stdc++.h> 
using namespace std; 

#define N 8 

bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                     {0, 0, 1, 0}, 
                     {0, 0, 0, 0}, 
                     {0, 0, 1, 0} 
}; 
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 

int findCelebrity(int n) 
{ 

    int a = 0; 
    int b = n - 1; 
 
    while (a < b) 
    { 
        if (knows(a, b)) 
            a++; 
        else
            b--; 
    } 

    for (int i = 0; i < n; i++) 
    { 

        if ( (i != a) && 
                (knows(a, i) ||  
                !knows(i, a)) ) 
            return -1; 
    } 
  
    return a; 
} 

int main() 
{ 
    int n = 4; 
    int id = findCelebrity(n); 
    id == -1 ? cout << "No celebrity" : 
               cout << "Celebrity ID " 
                    << id; 
    return 0; 
} 
