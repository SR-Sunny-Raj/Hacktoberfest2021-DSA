#include <iostream>
int toh(int, char, char, char);
using namespace std;
int main()
{

    int n;
    cout << "enter no. of disks ";
    cin >> n;
    toh(n, 'a', 'b', 'c');
}
int toh(int n, char s, char a, char d)
{
    //Your Code Here
     if (n == 1)
    {
        cout << "Move disk 1 from rod " << s <<
                            " to rod " << a <<endl;
        return 0;
    }
    toh(n - 1, s, d, a);
    cout << "Move disk " << n << " from rod " <<s <<
                                " to rod " <<a<< endl;
    toh(n - 1,d,a,s);
    return 0;
}
