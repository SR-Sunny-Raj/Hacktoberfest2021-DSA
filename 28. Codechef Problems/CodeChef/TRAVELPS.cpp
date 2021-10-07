#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    if(T>=1)
    {
    for(int i=0;i<T;i++)
    {
        //A,0-dis, B,1-sta
        int N,A,B,t=0;
        string str;
        cin>>N>>A>>B;
        cin>>str;
        for(int j=0;j<N;j++)
        {
            if(str[j]=='0')
            t=t+A;
            else if(str[j]=='1')
            t=t+B;
        }
        cout<<t<<endl;
    }
    }
	return 0;
	
}
