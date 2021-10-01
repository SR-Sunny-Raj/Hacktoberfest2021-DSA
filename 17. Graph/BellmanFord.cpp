#include<bits/stdc++.h>
using namespace std;


bool ford(vector<tuple<int,int,int>>&vec,int size,int start,vector<int>&v){
    
    
    for(int i=1;i<size;i++){
        for(auto x=vec.begin();x!=vec.end();x++){
            int p=get<0>(*x);
            int q=get<1>(*x);
            int r=get<2>(*x);
            if(v[q]>v[p]+r){
                v[q]=v[p]+r;
            }
        }
    }
   for(auto x=vec.begin();x!=vec.end();x++){
            int p=get<0>(*x);
            int q=get<1>(*x);
            int r=get<2>(*x);
            if(v[q]>v[p]+r){
                return false;
            }
        }

    return true;
}
int main(){
    int size=5;
vector<tuple<int,int,int>>vec;
vec.push_back(make_tuple(0,1,4));
vec.push_back(make_tuple(0,2,2));
vec.push_back(make_tuple(1,3,2));
vec.push_back(make_tuple(1,4,3));
vec.push_back(make_tuple(1,2,3));
vec.push_back(make_tuple(2,1,1));
vec.push_back(make_tuple(2,4,5));
vec.push_back(make_tuple(2,3,4));
vec.push_back(make_tuple(4,3,-5));
vector<int>v(size,INT_MAX);
v[0]=0;
if(ford(vec,size,0,v)){
    for(int i=0;i<size;i++){
        cout<<"0 ->"<<i<<" "<<v[i]<<endl;
    }
}
else cout<<"not exists";


    return 0;
}