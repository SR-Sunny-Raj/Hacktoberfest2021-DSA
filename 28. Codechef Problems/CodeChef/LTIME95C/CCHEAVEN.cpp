/*

Problem Name: Chef in Heaven
CodeChef Link: https://www.codechef.com/LTIME95C/problems/CCHEAVEN/
Problem Code: CCHEAVEN

*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	
	cin >> t;
	
	for (int i = 0; i < t; i++){
	    int l;
	    cin >> l;
	    string s;
	    cin >> s;
	    int x = 0; //ones
	    int y = 0; //zeroes
	    int dec = 0;
	    for (int j = 0; j < l; j++){
	        if (s[j] == '1'){
	            x += 1;
	        }
	        else{
	            y += 1;
	        }
	        if (x >= y){
    	        dec = 1;
    	        break;
	        }
	    }
	    
	    if (dec == 1){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	
	return 0;
}
