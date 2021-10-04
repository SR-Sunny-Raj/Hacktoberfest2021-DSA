// Link for Problem->https://codeforces.com/contest/1579/problem/E1

//We'll process the permutation elements one by one.

//For the first element, it doesn't matter which side of the deque we add it to, the result of its addition will be the same — 
//there will be a sequence of one element (equal to the first permutation element) in the deque.

//Now let's consider adding the i-th element of a permutation to the deque. First i=2 will be considered, then i=3, and so on up to i=n. 
//Let us describe the general algorithm for choosing the side of the deque for each step. Note that if the elements [d1,…,di−1] are now in the deque, 
//then all final permutations that can be obtained in the deque from the current state can be broken down into pairs of the form
//[…,ai,d1,…,di−1,…]
//[…,d1,…,di−1,ai,…],
//where the beginning and the end of the final permutations, hidden behind "…", are obtained by the same sequences of all the following choices and thus are equal between the first and the second.

//Note that when ai<d1 the first permutation will always be lexicographically smaller than the second one, and vice versa. 
//Therefore, regardless of the following choices, if ai<d1 then the second permutation will never be minimal, and if ai>d1 then the first permutation will never be minimal.

//This means that we can make a choice about the side of the deque to add the i-th element to based only on its relation to d1: if ai<d1, then ai is added to the beginning of the deque, otherwise — to the end.

//The time complexity is O(n). Alternative solutions, which also fit in the time limit, 
//involved finding a lexicographically minimal increasing sequence in the reversed original permutation and could be implemented either with O(nlogn) time complexity or with O(n) time complexity if the permutation's definition was taken into consideration.
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int j=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1){
				j=i;
			}
		}
		deque <int> dq;
		dq.push_back(a[0]);
		for(int i=1;i<j;i++){
			if(dq[0]<a[i]){
				dq.push_back(a[i]);
			}
			else{
				dq.push_front(a[i]);
			}
		}
		if(j!=0){
           dq.push_front(1);
		}
		for(int i=j+1;i<n;i++){
			dq.push_back(a[i]);
		}
		 for (int i=0;i<dq.size();i++){
		 	        cout <<dq[i]<<" ";
		 }
		 cout<<endl;
	}
}