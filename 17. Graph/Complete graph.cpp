#include<iostream> 
using namespace std; 
int main() 
{  
    int v,count=0,count1=0,b,q; 
    cout<<"Enter the number of vertices: "; 
    cin>>v; 
    cout<<endl;
    int arr[100][100]; 
    for(int i=0;i<v;i++) 
    { 
        for(int j=0;j<v;j++) 
        { 
            cout<<"How many edge from "<<(char)(97+i)<<" to "<<(char)(97+j)<<" : "; 
            cin>>arr[i][j]; 
        } 
    }
    cout<<endl<<"Adjancy matrix of graph : \n"; 
    for(int k=0;k<v;k++) 
    { 
        cout<<endl;
        for(int l=0;l<v;l++) 
        cout<<arr[k][l]<<" "; 
    } 
    for(int p=0;p<v;p++) 
    { 
        cout<<endl; 
        for(int q=0;q<v;q++) 
        { 
            if(arr[p][q]==1 && (p!=q)) 
            { 
                count++;
            } 
            else if(arr[p][q]==0 && (p==q))
            {
            	count1++;
			}
        } 
    } 
    b=v*v-v;
	if(count==b && count1==v) 
    { 
        cout<<"It is a complete graph\n"; 
    } 
    else 
    { 
        cout<<"It is not a complete graph\n"; 
    } 
} 
