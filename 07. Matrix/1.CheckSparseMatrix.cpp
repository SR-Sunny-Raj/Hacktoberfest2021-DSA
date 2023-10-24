//To check if a given Matrix is a Sparse Matrix or not
#include<iostream>
using namespace std;
int main()
{
    int r,c;
    cout<<"Enter No. of Rows of Matrix :";
    cin>>r;
    cout<<"Enter No. of Columns of Matrix :";
    cin>>c;

    cout<<endl;

    int a[100][100];
    int zeroes = 0 ;
    int nonzero = 0 ;

    for(int i=0 ; i<r ; i++){

        for(int j=0 ; j<c ; j++){

            cout<<"Enter Element A["<<i<<"]["<<j<<"] : ";
            cin>>a[i][j];
        }
    }

    for(int i=0 ; i<r ; i++){

        for(int j=0 ; j<c ; j++){

            if(a[i][j] == 0)
                zeroes++;
            else
                nonzero++;
        }
    }

    if(zeroes > nonzero)
    {
        cout<<endl<<"The Given Matrix is a SPARSE MATRIX"<<endl;
    }
    else
    {
        cout<<endl<<"The Given Matrix is NOT a SPARSE MATRIX"<<endl;
    }

    return 0;
}
