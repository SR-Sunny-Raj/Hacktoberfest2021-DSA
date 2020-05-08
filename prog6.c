#include <stdio.h>
int main()
{
	int binary,decimal=0,weight=1,rem;
	printf ("Enter any Binary number to convert it into decimal : ");
	scanf ("%d",&binary);
	while (binary!=0)
	{
		rem=binary%10;
		decimal=decimal+rem*weight;
		weight=weight*2;
		binary=binary/10;
	}
	printf ("The Decimal representation of the given binary number is : %d",decimal);
	return 0;
}
