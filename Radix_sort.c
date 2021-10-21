#include<stdio.h>
int radix_sort(int a[], int n)
{
	int bucket[10][10],bucket_count[10];
	int i,j,k,remainder,nop=0,divisor=1,large,pass;
	large=largest(a,n);
	while(large>0)
	{
		nop++;
		large/=10;
	}
	for(pass=0;pass<nop;pass++){
		for(i=0;i<10;i++){
			bucket_count[i]=0;
		}
		for(i=0;i<n;i++){
			remainder=(a[i]/divisor)%10;
			bucket[remainder][bucket_count[remainder]]=a[i];
			bucket_count[remainder]+=1;
		}
		i=0;
		for(k=0;k<10;k++){
			for(j=0;j<bucket_count[k];j++){
				a[i]=bucket[k][j];
				i++;
			}
		}
		divisor*=10;
		
	}	
}
