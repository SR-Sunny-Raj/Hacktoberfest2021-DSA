#include <bits/stdc++.h>

using namespace std;

bool desc(int num1, int num2)
{
	// returns true, when no need of swap
	// returns false, when we need to swap
	return num1 > num2 ;

	// Note : better to use < or > operator . Caution : don't use >= or <=
}

bool comp(pair<int, int> p1, pair<int, int> p2){
	return (p1.second<p2.second) || (p1.second==p2.second && p1.first < p2.first );
}

struct student
{
	int marks;
	int rno;
	string name;
};

// First, sort by marks in desc, then by name in ascending order, then by rno in ascending order
// i.e. sort by name only when marks of 2 students are equal
// ans sort by rno only when both marks and name of 2 students are equal
bool comp2(student s1, student s2)
{
	// better to use < or > operator . Caution : don't use >= or <=
    return (s1.marks > s2.marks) || ( s1.marks == s2.marks && s1.name < s2.name )
    || ( s1.marks==s2.marks && s1.name == s2.name && s1.rno < s2.rno);
}

int main()
{

cout<<"(-4)%3 = "<<(-4)%3<<'\n';

int a=12;
char ch='c';
pair<int,char> p={a,ch};
cout<<"Pair p : ";
cout<<p.first<<" "<<p.second<<'\n';

vector<pair<int,int> > vp={{4,7},{2,8},{1,7},{2,4}};

sort(vp.begin(),vp.end()); // By default, sorts by first, if first is equal, then compares second

cout<<"Default sorting of vector of pair vp: \n";
for(int i=0; i<(int)vp.size(); i++)
{
	cout<<"("<<vp[i].first<<","<<vp[i].second<<")  ";
}
cout<<'\n';

vector<int> arr={5,1,2,8};

cout<<"Sorting array of integers arr in descending order: \n";
// sort array of integers in descending order , without using greater<int>
sort(arr.begin(),arr.end(),desc);

for(int i=0; i<(int)arr.size(); i++)
{
	cout<<arr[i]<<" ";
}
cout<<'\n';

cout<<"Sorting array of pairs by second element first, and if second are equal, then compare by first element: \n";
// Now, sort vector of pairs by second, if second are equal then compare by first element
vector<pair<int,int> > vec={{4,7},{2,8},{1,7},{2,4}};

sort(vec.begin(),vec.end(),comp);

for(int i=0; i<(int)vec.size(); i++)
{
	cout<<vec[i].first<<" "<<vec[i].second<<'\n';
}

vector<student> slist={{83,13,"rahul"},{92,55,"sachin"},{92,22,"sachin"},{42,1,"vikram"},{42,3,"arjun"},{100,55,"ramesh"}};

cout<<"Sorting students first by marks in descending order, then by name in ascending order (in order of dictionary) and then by roll no. in ascending order :\n";
sort(slist.begin(),slist.end(),comp2);

cout<<"Marks Rno Name \n";
for(int i=0; i<(int)slist.size(); i++)
{
	cout<<slist[i].marks<<"   "<<slist[i].rno<<"  "<<slist[i].name<<'\n';
}
return 0;
}
