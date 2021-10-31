#include<iostream>
using namespace std;

int main()
{

        int arr1[5][5], arr2[5][5], arr3[5][5], sub, i, j,m,n;

    cout<<"Enter size of matrix ( Max:5 ) :: ";
    cin>>m;
    cout<<"\nEnter Elements to Matrix A Below :: \n";

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;++j)
        {
            cout<<"\nEnter arr1["<<i<<"]["<<j<<"] Element :: ";
            cin>>arr1[i][j];
        }

    }

    cout<<"\nEnter Elements to Matrix B Below :: \n";

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;++j)
        {
            cout<<"\nEnter arr2["<<i<<"]["<<j<<"] Element :: ";
            cin>>arr2[i][j];
        }

    }


        cout<<"\nAdding Matrix ( A + B ) ..... \n";
        for(i=0; i<m; i++)
        {
                for(j=0; j<m; j++)
                {
                        arr3[i][j]=arr1[i][j]+arr2[i][j];
                }
        }

        cout<<"\nAfter Addition, Matrix C is :: \n";

        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                cout<<"\t"<<arr3[i][j];
            }
            printf("\n\n");
        }

        return 0;
}
