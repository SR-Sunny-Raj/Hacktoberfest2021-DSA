#include<conio.h>
#include<iostream>
using namespace std;

struct record{
	char name[100];
	int roll_no;
	char branch[10];
};

int main(){
	int i;
	struct record r[5];
	cout<<"enter the name, roll no. and branch";
	for(i=0;i<5;i++){
		cin>>r[i].name>>r[i].roll_no>>r[i].branch;
	}
	cout<<"details of students are under";
	for(i=0;i<5;i++){
		cout<<"\n"<<r[i].name<<r[i].roll_no<<r[i].branch;
	}
	return 0;
}