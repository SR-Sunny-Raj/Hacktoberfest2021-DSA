// Nearest smaller to the left

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
	int arr[] = {1,3,2,4}; // ans - -1 1 1 2
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> v;
	stack<int> s;

	for(int i=0; i<n ; i++){
		if(s.size()==0)
			v.push_back(-1);

		else if(s.size()>0 && s.top()<arr[i])
			v.push_back(s.top());

		else if(s.size()>0 && s.top()>=arr[i]){
			while(s.size()>0 && s.top()>=arr[i])
				s.pop();

			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}

	for(int i=0 ; i<v.size() ; i++)
		cout<<v[i]<<" ";

	return 0;
}
