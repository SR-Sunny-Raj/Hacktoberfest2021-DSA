#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
return (3*x+ sin(x)- exp(x));
}
int main()
{
int itr=0, maxitr;
float x1,x2,x3,x4,aerr;
printf("\nEnter value of x0, x1, allowed error and maximum iteration\n");
scanf("%f %f %f %d", &x1, &x2, &aerr, &maxitr);
x3=((x1*f(x2))-(x2*f(x1)))/(f(x2)-f(x1));

do
{
if (f(x1)*f(x3)<0)
x2=x3;
else
x1=x3;
x4=x3;
x3=((x1*f(x2))-(x2*f(x1)))/(f(x2)-f(x1));
itr++;
if (fabs(x4-x3)<aerr)
{
printf("\n\nRoot= %f",x4);
getch();
return 0;
}
}
while (itr<maxitr);
printf("\n\nSolution does not converge");
getch();
return 1;
}