// SWAP ALL ODD AND EVEN BITS


//Time complexity : O(1)


#include<bits/stdc++.h>
using namespace std;


unsigned int swapBits(unsigned int n)
{
    // Your code here
    unsigned int res = 0;
    for(int i=31; i>0; i-=2){
        int firstPos = (n>>i)&1;//n&((unsigned int)1<<i);
        int secondPos = (n>>(i-1))&1;//n&((unsigned int)1<<(i-1));
        res = res*2+secondPos;
        res = res*2+firstPos;
    }
    return(res);
}


int main()
{
	
		unsigned int n;
		cin>>n;//input n
		
		//calling swapBits() method
		cout << swapBits(n) << endl;
	return(0);
}  