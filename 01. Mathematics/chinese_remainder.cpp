
#include<iostream>
using namespace std;


class chinese_remainder
{
    public:

    int total_product = 1;
    int N;
    int Ni[100];
    int yi[100];
    int n[100];
    int b[100];
    void get_data();
    void evaluate();
    bool relative_prime();
    static int gcd(int a, int b);

};


void chinese_remainder::get_data()
{

    cout << "\nEnter no. of divisors : ";
    cin >> N;

    cout << "\nEnter values of divisor (n) : ";

    for(int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    cout<<"\nEnter values of remainder (b) : ";
    
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

}


int chinese_remainder::gcd(int a, int b)
{
    if (b == 0)
    return a;
      
    return gcd(b, a%b);
}


bool chinese_remainder::relative_prime()
{

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if( gcd(n[i], n[j]) != 1)
              return false;
        }
        
    }

    return true;
}


void chinese_remainder::evaluate()
{
    int ans = 0, j =1;
    float k = 2.4;

    // Calculating total product of divisors
    for (int i = 0; i < N; i++)
    {
        total_product = total_product * n[i] ;
    }

    cout << "\nTotal product of divisors (n) is : " << total_product << "\n";

    for (int i = 0; i < N; i++)
    {
        Ni[i] = total_product/n[i];
    }

    cout<<"\n";


    for (int i = 0; i < N; i++)
    {
        yi[i] = 1;
    }
    
    cout<<"\n";

    for (int i = 0; i < N; i++)
    {
        // Loop for finding out modular multiplicative inverse

        for(int j = 1; j < n[i]; j++)          
        {
            if((Ni[i]*j) % n[i] == 1)         
                yi[i] = j;
        }

    }

    for (int i = 0; i < N; i++)
    {
        ans += b[i]*Ni[i]*yi[i] ;
    }

    ans = ans % total_product;

    cout << "\nbi\tNi\tyi\tbiNiyi";

    for (int i = 0; i < N; i++)
    {
        cout << "\n\n" << b[i] << "\t" << Ni[i] << "\t" << yi[i] << "\t" << b[i]*Ni[i]*yi[i];
    }
    
    cout<<"\n\nNumber is " << ans;
}


int main()
{
    chinese_remainder c;
    c.get_data();

    if(c.relative_prime())
    {
        c.evaluate();
    }
    else
    {
        cout << "Divisors (n) are not relative prime !!!\n";
    }
    
    return 0;

}
