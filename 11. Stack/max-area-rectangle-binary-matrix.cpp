// Maximum Area Rectangle in binary matrix
// Divide the rows in diff histograms and get the Maximum area histogram to solve the question
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int mah(vector<int> &arr){
    int n = 4;
  // NSL
	vector<int> left;
	stack<pair <int, int>> s1;

    int pseudo_index = -1;
	for(int i=0; i<n ; i++){
		if(s1.size()==0)
			left.push_back(pseudo_index);

		else if(s1.size()>0 && s1.top().first<arr[i])
			left.push_back(s1.top().second);

		else if(s1.size()>0 && s1.top().first>=arr[i]){
			while(s1.size()>0 && s1.top().first>=arr[i])
				s1.pop();

			if(s1.size()==0)
				left.push_back(pseudo_index);
			else
				left.push_back(s1.top().second);
		}
		s1.push({arr[i], i});
	}
  
  // NSR
    pseudo_index = 7;
    vector<int> right;
	stack<pair <int, int>> s2;
	for(int i=n-1; i>=0; i--){
		if(s2.size()==0)
			right.push_back(pseudo_index);

		else if(s2.size()>0 && s2.top().first<arr[i])
			right.push_back(s2.top().second);

		else if(s2.size()>0 && s2.top().first>=arr[i]){
			while(s2.size()>0 && s2.top().first>=arr[i])
				s2.pop();

			if(s2.size()==0)
				right.push_back(pseudo_index);
			else
				right.push_back(s2.top().second);
		}
		s2.push({arr[i], i});
	}
	reverse(right.begin(), right.end());
  
  
	int width[n] = {};
	int area[n] = {};
	for(int i=0; i<n; i++)
	    width[i] = right[i] - left[i] - 1;
	for(int i=0; i<n; i++)
	    area[i] = width[i]*arr[i];
	return *max_element(area, area + n);
}
int main(){
	int arr[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}}; 
	int m = 4;
	int n = 4;
    vector <int> v;
    for(int j=0; j<m; j++)
        v.push_back(arr[0][j]);
    int mx = mah(v);
    cout << mx << endl;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0)
                v[j] = 0;
            else
                v[j] = v[j] + arr[i][j];
        }
        mx = max(mx, mah(v));
        cout << mx << endl;
    }
    cout << mx;
    return 0;
}
