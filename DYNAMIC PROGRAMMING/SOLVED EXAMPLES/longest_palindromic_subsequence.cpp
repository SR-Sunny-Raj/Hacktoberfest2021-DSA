//Longest Palindromic Subsequence

//Time Complexity : O(n^2)

#include <iostream>
using namespace std;

int lps(string str){
    int n=str.length();
	int lps[n][n];
	// when n=1 
    for(int i=0 ; i<n ; i++){
        lps[i][i] = 1;
   }
   
	for(int k=2 ; k<=n ; k++){
        for(int i=0 ; i<n-k+1 ; i++){
            int j = i+k-1;
          
	          if(str[i] == str[j]){
	              //if length is 2 and both characters are same return 2
	            lps[i][j] = (k == 2) ? 2 : (2 + lps[i+1][j-1]);
            }else{
                //if the first and last char doesnt match
               lps[i][j] = max(lps[i+1][j] , lps[i][j-1]);
	        }
	   }
   }
	 return lps[0][n-1];
}

int main() 
{ 
    
    string str; 
    cin >> str;
    cout << "Length of Longest Palindromic Subsequence in " << str << " is : " << lps(str);  
    return 0; 
}
