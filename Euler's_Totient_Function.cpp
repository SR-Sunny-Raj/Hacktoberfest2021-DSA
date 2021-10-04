// Euler's Totient Function

/*Euler's totient function, also known as phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are coprime to n.
 Two numbers are coprime if their greatest common divisor equals 1 (1 is considered to be coprime to any number).
*/

#include<iostream>
using namespace std;
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0){
                n = n/ i;
            }
            result = result - (result / i);
        }
    }
    if (n > 1){
        result = result - (result / n);
    }
    return result;
}
int main(){
    int n;
    for (n = 1; n <= 10; n++)
        cout << "phi("<<n<<") = " << phi(n) << endl;
    
    return 0;
}

// OUTPUT :
/* 
    phi(1) = 1
    phi(2) = 1
    phi(3) = 2
    phi(4) = 2
    phi(5) = 4
    phi(6) = 2
    phi(7) = 6
    phi(8) = 4
    phi(9) = 6
    phi(10) = 4
*/
