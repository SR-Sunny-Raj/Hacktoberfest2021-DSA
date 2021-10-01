/*
Problem Statement:

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


Constraints:

matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/



#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int a = 0;
	int b = n - 1;
	while (a < b) {
		for (int i = 0; i < (b - a); ++i) {
			swap(matrix[a][a + i], matrix[a + i][b]);
			swap(matrix[a][a + i], matrix[b][b - i]);
			swap(matrix[a][a + i], matrix[b - i][a]);
		}
		++a;
		--b;
	}
	return matrix;
}


int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n, m;
		vector<vector<int> > nums(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> nums[i][j];
			}
		}

		vector<vector<int> > result;
		result = rotate(nums);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << nums[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}
