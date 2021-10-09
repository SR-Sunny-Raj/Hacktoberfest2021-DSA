/*
CodeChef Solution
Problem: STRAIGHT LINE
Problem CODE:CDM101
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int arr[8];
    int arrU[8];
    int k;
    
    for(int i=0;i<8;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    
    cin>>k;
    
    while(k--){
        
        for(int i=0;i<8;i++){
            if(i==0){
              arrU[i]=arr[i+1];
            }
            
			else if(i==7){
                arrU[i]=arr[i-1];
            }
            
            else{
                
				if(arr[i-1]==arr[i+1]){
                    arrU[i]=0;
                }
                
                else{
                    arrU[i]=1;
                }
            }
            
        }
        
        if(k!=0){
            for(int i=0;i<8;i++){
                arr[i]=arrU[i];
                
            }
        }
        
    }
    
    for(int i=0;i<8;i++){
        
        cout<<arrU[i]<<" ";
    }
    
    
    return 0;
}
