//not an encryption algo
//It is used to exhange secret key
//asymetric encryption to exchange secret key b/w users
//using concept of public and private key

//consider a prime number 'q'
//select alpha, alpha<q and (alpha is a primitive root of q)
//alpha and q are public elements

//x_a=private key of a, x<q
//y_a=public key of a, y_a= alpha^x_a mod q
//x_b=private key of b, x_b<q
//y_b=alpha^x_b mod q, public key  of b
//calculate secret key which had to be exchanged, both heys should be same
//use public keys to calculate secret key
//key_a=(y_b^x_a) mod q
//key_b=(y_a^x_b) mod q


#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int q=23;
    long long int alpha=9;
    long long int x_a;
    cout<<"enter private key of a, eg:4"<<endl;
    cin>>x_a;
    long long int y_a=fmod(pow(alpha,x_a),q);
    long long int x_b;
    cout<<"enter private key of b,eg: 3"<<endl;
    cin>>x_b;
    long long int y_b=fmod(pow(alpha,x_b),q);
    long long int key_a,key_b;
    key_a=fmod(pow(y_b,x_a),q);
    key_b=fmod(pow(y_a,x_b),q);
    cout<<"secret key of a="<<key_a;
    cout<<endl<<"secret key of b="<<key_b;
    return 0;
}

