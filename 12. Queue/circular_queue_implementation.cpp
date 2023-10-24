// Circular_Queue
#include <iostream>
using namespace std;

class queue{
	int f;
	int r;
	int cs;
	int *a;
	int n;
public:
	queue(int s=4){
		a = new int[s];
		f=0;
		n = s;
		r=n-1;
		cs = 0;
	}

	void push(int d){
		if(cs == n){
			// That means we cannot insert more elements
			cout<<"Overflow"<<endl;
		}
		else{
			r = (r+1)%n;
			a[r] = d;
			cs++;
		}
	}

	void pop(){
		if(cs == 0){
			cout<<"Underflow"<<endl;
		}
		else{
			f = (f+1)%n;
			cs--;
		}
	}	

	int front(){
		return a[f];
	}

	bool empty(){
		return cs==0;
	}

};

int main(){
	queue q;

	q.push(4);
	q.push(3);
	q.push(2);
	q.push(1);
	// q.push(0);
	q.pop();
	q.push(5);

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	q.pop();

	return 0;
}