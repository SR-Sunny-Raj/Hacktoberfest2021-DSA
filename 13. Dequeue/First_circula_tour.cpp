#include<bits/stdc++.h>
using namespace std;

//Function to return whether the tur can be completed or not.
int firstPetrolPump(int petrol[],int dist[],int n){
    int start =0,curr_pet = 0;
    int prev_pet = 0;

    for(int i=0;i<n;i++){
        curr_pet += (petrol[i] - dist[i]);
        // when there is no petrol to go forwad.
        if(curr_pet < 0){
            start = i+1;
            prev_pet += curr_pet;
            curr_pet = 0;
        }
    }
    return ((curr_pet+prev_pet >= 0))? (start+1) : -1;
}

int main(){

//Fast i-o
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;
    cin>>n;
    int petrol[n],dist[n];
    //array to store petol.
    for(int i=0;i<n;i++){
        cin>>petrol[i];
    }
    //aray to store the distance between petrol pumps.
    for(int i=0;i<n;i++){
        cin>>dist[i];
    }

//If no possible route is found.
    if(firstPetrolPump(petrol,dist,n) == -1){
        cout<<"No Solution";
    }
    else{
        cout<<firstPetrolPump(petrol,dist,n);
    }

    return 0;
}