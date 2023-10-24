#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x,stud,higt;
        cin>>stud;
    int ar1[stud];
    
        for(x=0;x<stud;x++)
            cin>>ar1[x];
        cin>>higt;
    
    int ar2[higt];
        for(x=0;x<higt;x++)
            cin>>ar2[x];
    
    int ar3[stud+higt];
        for(x=0;x<stud;x++)
            ar3[x]=ar1[x];
        for(x=stud;x<stud+higt;x++)
            ar3[x]=ar2[x-stud];
    sort(ar3,ar3+stud+higt);
        for(x=0;x<stud+higt;x++)
            cout<<ar3[x]<<" ";
    return 0;
}
