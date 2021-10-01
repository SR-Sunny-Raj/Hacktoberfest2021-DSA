#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;

int readline(char *str) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int a1[100001];
int a2[100001];
int a3[100001];

int main(int argc, char *argv[]) {
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);

    int h1 = 0, h2 = 0, h3 = 0;

    for(int i = 0 ; i < n1; i++) {
        scanf("%d", &a1[i]);
        h1 += a1[i];
    }
    for(int i = 0 ; i < n2; i++) {
        scanf("%d", &a2[i]);
        h2 += a2[i];
    }
    for(int i = 0 ; i < n3; i++) {
        scanf("%d", &a3[i]);
        h3 += a3[i];
    }

    int i1 = 0, i2 = 0, i3 = 0;

    while(!(h1 == h2 && h2 == h3)) {
        if( i1 < n1 && (h1 > h2 || h1 > h3) ) {
            h1 -= a1[i1];
            i1++;
            // printf("Moving from 1 new height = %d\n", h1);
        }
        else if(i2 < n2 && (h2 > h1 || h2 > h3)) {
            h2 -= a2[i2];
            i2++;
            // printf("Moving from 2 new height = %d\n", h2);
        }
        else if(i3 < n3 && (h3 > h1 || h3 > h2) ) {
            h3 -= a3[i3];
            i3++;
            // printf("Moving from 3 new height = %d\n", h3);
        }
    }

    printf("%d\n", h1);

    return 0;
}