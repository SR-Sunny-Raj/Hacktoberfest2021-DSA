#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int cnt=0;
        int sum1=capacityA;
        int sum2=capacityB;
        for(int i=0;i<(n/2);i++){
            if(plants[i]<=capacityA){
                capacityA=capacityA-plants[i];
            } 
            else{
                capacityA=sum1;
                capacityA=capacityA-plants[i];
                cnt+=1;
                
            }
            if(plants[n-1-i]<=capacityB){
                capacityB=capacityB-plants[n-1-i];
            }
            else{
                capacityB=sum2;
                capacityB=capacityB-plants[n-1-i];
                cnt+=1;
            }
          
        }
        if(n%2!=0){
            int cp=max(capacityA,capacityB);
            if(cp<plants[n/2]){
                cnt+=1;
            }
        }
        return cnt;
   }


int main(){
	vector<int> a{2,2,3,3};
	int capacityA=5;
	int capacityB=5;
	int number_of_steps=wateringPlants(a,capacityA,capacityB);
	cout<<"Number of steps needed ";
	cout<<number_of_steps;
	cout<<"\n";
	return 0;
}   