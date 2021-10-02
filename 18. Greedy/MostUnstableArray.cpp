#include <iostream>
 /*
 You are given two integers n and m. You have to construct the array a of length n consisting of non-negative integers (i.e. integers greater than or equal to zero) such that the sum of elements of this array is exactly m and the value ∑i=1n−1|ai−ai+1| is the maximum possible. Recall that |x| is the absolute value of x.

In other words, you have to maximize the sum of absolute differences between adjacent (consecutive) elements. For example, if the array a=[1,3,2,5,5,0] then the value above for this array is |1−3|+|3−2|+|2−5|+|5−5|+|5−0|=2+1+3+0+5=11. Note that this example doesn't show the optimal answer but it shows how the required value for some array is calculated.

You have to answer t independent test cases.
 */
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    
    while(t!=0){
        int n,m;
        cin>>n;
        cin>>m;
        if(n==1){
            cout<<0<<endl;
        }else if(n>=3){
            cout<<m*2<<endl;
        }
        else if(n>=2){
            cout<<m<<endl;
        }
        
        t=t-1;
    }
    return 0;
}
