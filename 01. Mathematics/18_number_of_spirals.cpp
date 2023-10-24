//CSES Problem Set "Number Spiral" in a Mathematical approach

#include <iostream>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	//taking testcases
	cin>>t;
	while(t--){
	    long x,y;
	    cin>>x>>y;
	    long n = (x>y)?x:y;
		
	    long res = n*n -n +1; //From series pattern observed from the spiral given in the Problem Set, we can derive at this "General Term" of the series.
	    if(n%2==0){
	        res = res + (x - y);
	    }else{
	        res = res + (y - x);
	    }
	    cout<<res<<"\n";
	}
	return 0;
}