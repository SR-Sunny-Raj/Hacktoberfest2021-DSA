/* 
A series of numbers in which each number ( Fibonacci number ) is the sum of the two preceding numbers. 
The simplest is the series 1, 1, 2, 3, 5, 8, etc.
Here is simplest C++ program for Fibonacci series
*/
#include <iostream>
using namespace std;
int main(){
	int first=0;
	int second=1;
	int temp,num;
	cout<<"Enter a number: ";
	cin>>num;
	cout<<"Here is Fibonacci Series till "<<num<<endl;
	cout<<first<<endl<<second<<endl;
	for(int i=0; i<num-2; i++)
	{
		
	temp=first +second;
	    first=second;
	    second=temp;
		
		cout<<temp<<endl;
		
	}
}
