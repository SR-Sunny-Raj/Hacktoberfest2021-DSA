#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        string answer = "NO";
        //int sumleft=0,sumright=0;
        for(int i=0;i<n;i++){

            int sumleft=0,sumright=0;
            if(i==0){
                for(int l=i+1;l<n;l++){
                    sumright = sumright + arr[l];
                }
                if(sumright==0){
                    answer = "YES";
                }
            }
            else if(i==n-1){
                for(int r=0;r<n-1;r++){
                    sumleft = sumleft + arr[r];
                }
                if(sumleft==0){
                    answer = "YES";
                }
            }
            else{
                for(int j=0;j<i;j++){
                    sumleft = sumleft + arr[j];
                    //cout<<"L "<<sumleft<<endl;
                }
                for(int k=i+1;k<n;k++){
                    sumright = sumright + arr[k];
                    //cout<<"R "<<sumright<<endl;;
                }
                if(sumright==sumleft){
                    answer = "YES";
                }
            }


        }
        cout<<answer<<endl;
    }
    return 0;
}
