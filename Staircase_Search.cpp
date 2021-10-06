//  main.cpp
//  Staircase_Search
//
//  Created by kshitiz on 04/06/21.
//  Copyright © 2021 c++ codes. All rights reserved.
//

#include <iostream>
using namespace std;

void staircase_search(int a[1000][1000], int m, int n, int key){
    int row = 0;
    int end_col = n - 1;
    int flag=0;
    
    
        for(int j=end_col; j>=0; j--){
            if(a[row][end_col] < key){
                row++;
                j++;
            }
            else{
                end_col--;
            }
            if(key == a[row][j]){
                cout<<"\n"<<row<<" "<<j<<"\n";
                flag=1;
                break;
            }
            
        }
       
    if(flag==0){
        cout<<"\nElement not found\n";
    }
    
    
}


int main() {
    int a[1000][1000];
    int m,n;
    
    cin>>m>>n;
    
    int val = 1;
    for (int i=0;i<=m-1 ;i++){
        for(int j=0;j<=n-1 ;j++){
            a[i][j]=val;
            val = val + 1;
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
    int key;
    cin>>key;
    staircase_search(a, m, n, key);

    
    return 0;
}
