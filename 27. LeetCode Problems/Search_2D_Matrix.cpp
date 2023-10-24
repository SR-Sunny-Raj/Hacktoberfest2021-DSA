//question: https://leetcode.com/problems/search-a-2d-matrix/
//binary search
//time complexity O(m+n)
/*
   Do binary search in this "ordered" matrix
1. if matrix[row][col] is equal target,return true.
2. if matrix[row][col] is less than target, row++; indicate that this row can't contain target.because this one in this line is the biggest one,counting from 'row'.
3. if matrix[row][col] is greater than target,col--; indicate that this column can't contain target.because this one in this column is the smallest one,counting from 'col'.
 */
#include<iostream>
#include<vector>
using namespace std;
bool matrix_search(vector<vector<int>>a,int target){
    int n=a.size();
    int m=a[0].size();
	int i=0,j=m-1;
	while(i<n&&j>=0){
		if(a[i][j]==target)
		return true;
		else
		{
			if(a[i][j]>target)
			j--;
			else
			i++;
		}
	}return false;
}
int main() {
	int n,m;
	cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	int x;
	cin>>x;
	if(matrix_search(a,x))
	cout<<"Found Element";
	else
	cout<<"Not Found Element";
	return 0;
}