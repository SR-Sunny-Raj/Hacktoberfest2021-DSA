#include<iostream>
#include"dyarrclass.cpp"
using namespace std;

int main(){

    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    dynamicarray d2=d1;
    d1.add(3,100);
    d1.print();
    d2.print();

    dynamicarray d3(d2);

    d3.print();

}