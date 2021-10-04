//Map is a data structure in STL
//map stores a pair
//mapping is done based on the key so that it can redirect to the string
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    map<int,string> m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="acd";
    m.insert({4,"afg"});
    map<int,string>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<" "<<endl;
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}