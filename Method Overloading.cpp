#include<iostream>
using namespace std;
class A
{
	private:
		int x;
	public:
		A(){ x=0; };   //default constructor
		A (int a)      //parameter constructor
		{ 
		   x=a; 
		}
		int getx()      //get function
		{
			return x;
		}
	bool operator < ( A obj2)   //relational operator-->used to check the relationship 
	{                          //between two operands. Example it checks here x (which is equal to 10)
		bool ans;           //is less than obj2 ( a2 passes the value to obj2 which is 18) or not.
	if (x<obj2.x)              //if the relation is true, it return 1 but if it is false  then 
		{                       //it returns 0.
			ans = true;          // for this we have a bool data type, which can take the values true(1) or false(0).
		}
		else
		{
			ans = false;
		}
	}
};
int main()
{
	A a1(10), a2(18), a3;
	cout<<a3.getx();
}
