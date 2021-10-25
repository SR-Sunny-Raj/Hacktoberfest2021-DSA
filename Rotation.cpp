// Program to rotate the matrix by 90 degree clockwise
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i= 0;i<matrix.size();i++){
        for (int j=i+1;j<matrix[i].size();j++)
            swap(matrix[i][j],matrix[j][i]);
    }
        
    }

int main(){
    int row;
    int size;
    cout<<"Enter the information for columns";
    cin>>size;
    int column[size];
    for(int i=0;i<size;i++){
        cout<<"Value for index "<<i<<" ";
        cin>>column[i];
    }
    cout<<"Enter the no. of rows" ;
    cin>>row;
    vector<vector<int>> vect(row);
    for(int j=0;j<row;j++){
        int col=column[j];
        vect[j]=vector<int>(col);
        for(int k=0;k<col;k++){
            vect[j][k]=j+1;
        }
    }
    for(int l = 0;l< row;l++){
        for (int m= 0;m<vect[l].size();m++){
            cout <<vect[l][m] << " ";
        }   
        cout << endl;
    }
    rotate(vect);
    for(int l = 0;l< row;l++){
        for (int m= 0;m<vect[l].size();m++){
            cout <<vect[l][m] << " ";
        }   
        cout << endl;
    }
    return 0;
}