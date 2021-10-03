#include <iostream>
using namespace std;
int main()
{
	int less = 0; //Same as lower - For is (VS) are
//---------------------------------------------------------------
	int user_input; // User entered number
	bool proper_input = false;
	int lower = 0; //Represents all #'s lower than user input
	int type_lower = 0; //Represents all #'s lower than user input - Used to find type of number
	int perfect_storage = 0; //Determines whether number is perfect, abundant, or deficient
	int zero = 0; //Zero
	int num_props = 0; //Number of proper factors
//---------------------------------------------------------------
	//Get number input
	do
	{
		cout << "Enter in a positive integer: ";
		try
		{
			cin >> user_input;
			proper_input = true;
		}
		catch (exception e)
		{
			cout << "That isn't a positive integer. " << endl;
		}
	} while (proper_input == false);
//---------------------------------------------------------------
		//Is vs Are
	for (less = user_input - 1; less > zero; less -= 1)
	{
		if (user_input % less == 0)
		{
			num_props += 1;
		}
	}
	//---------------------------------------------------------------
		//Print out proper factors answer 
	if (num_props == 1)
	{
		cout << "The proper factor of " << user_input << " is ";
	}
	else
	{
		cout << "The proper factors of " << user_input << " are: ";
	}
	//---------------------------------------------------------------
		//Reset variables
		num_props = 0;
	//---------------------------------------------------------------
		//Get proper factors of number - print out factors
	for (lower = user_input - 1; lower > zero; lower -= 1)
	{
		if (user_input % lower == 0)
		{
			if (lower == 1 && num_props + 1 > 1)
			{
				cout << " and ";
			}
			cout << lower;
			num_props += 1;
			if (lower == 3 && user_input % 2 != 0)
			{
				cout << "";
			}
			else if (lower > 2)
			{
				cout << ", ";
			}
		}
	}
	//---------------------------------------------------------------
		//Print out number of proper factors
	cout << endl << user_input << " has " << "(" << num_props << ")" << " proper factors.";
	cout << endl;
	//---------------------------------------------------------------
		//Get whether the number is perfect, abundant, or deficient
	for (type_lower = user_input - 1; type_lower > zero; type_lower -= 1)
	{
		if (user_input % type_lower == 0)
		{
			perfect_storage += type_lower;
		}
	}
	if (perfect_storage == user_input)
	{
		cout << user_input << " is a perfect number.";
	}
	else if (perfect_storage > user_input)
	{
		cout << user_input << " is an abundant number.";
	}
	else
	{
		cout << user_input << " is a deficient number.";
	}
}