#include <iostream>
using namespace std;

void reverse(const string& a);

int main()
{
    string str;
    cout << "\nPlease Enter any string :: ";
    getline(cin, str);

    cout<<"\nReverse of String [ "<<str<<" ] is :: ";
    reverse(str);

    return 0;
}

void reverse(const string& str)
{
    size_t numOfChars = str.size();

    if(numOfChars == 1)
       cout << str << endl;
    else
    {
       cout << str[numOfChars - 1];
       reverse(str.substr(0, numOfChars - 1));
    }
}
