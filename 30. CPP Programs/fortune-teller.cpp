#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

//check if input is valid
// if not update with valid number
int checkInput(int num, int limit) {
	int update = 0;
	while (update <= 0 || update > limit) {
		if (num > 0)
			if (num <= limit)
				return num;
		cout << "	wrong data entered... Enter again(between 1-" << limit << "): ";
		cin >> update;
	}
	return update;
}

// check if input is valid
// if not update with valid number
int checkInput(int num) {
	int update = 0;
	while (update <= 0) {
		if (num > 0)
			return num;
		cout << "	wrong data entered... Enter again(positive number only): ";
		cin >> update;
	}
	return update;
}

string computeZodiac(int date, int month)
{
	string Asign = "";

	// checks month and date within the  
	// valid range of a specified zodiac 
	if (month == 12) {

		if (date < 22)
			Asign = "Sagittarius";
		else
			Asign = "capricorn";
	}

	else if (month == 1) {
		if (date < 20)
			Asign = "Capricorn";
		else
			Asign = "aquarius";
	}

	else if (month == 2) {
		if (date < 19)
			Asign = "Aquarius";
		else
			Asign = "pisces";
	}

	else if (month == 3) {
		if (date < 21)
			Asign = "Pisces";
		else
			Asign = "aries";
	}
	else if (month == 4) {
		if (date < 20)
			Asign = "Aries";
		else
			Asign = "taurus";
	}

	else if (month == 5) {
		if (date < 21)
			Asign = "Taurus";
		else
			Asign = "gemini";
	}

	else if (month == 6) {
		if (date < 21)
			Asign = "Gemini";
		else
			Asign = "cancer";
	}

	else if (month == 7) {
		if (date < 23)
			Asign = "Cancer";
		else
			Asign = "leo";
	}

	else if (month == 8) {
		if (date < 23)
			Asign = "Leo";
		else
			Asign = "virgo";
	}

	else if (month == 9) {
		if (date < 23)
			Asign = "Virgo";
		else
			Asign = "libra";
	}

	else if (month == 10) {
		if (date < 23)
			Asign = "Libra";
		else
			Asign = "scorpio";
	}

	else if (month == 11) {
		if (date < 22)
			Asign = "scorpio";
		else
			Asign = "sagittarius";
	}

	return Asign;
}

string* computeFortune(string arr[]) {
	ifstream new_file; 
    new_file.open("File1.txt");   
    if(!new_file){
    cout<<"No such file exists";
}
	for (int i = 0; i < 12; i++) {
		
		getline(new_file, arr[i], '#');
	}
	new_file.close();
	return arr;
}

string getFortune(string* arr, int month) {
	return arr[month - 1];
}

template<class T>
class List {
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node() {
			next = NULL;
			prev = NULL;
		}
		Node(T d) {
			data = d;
			next = NULL;
			prev = NULL;
		}
	};
	Node* head;
	Node* tail;
	int size;
public:
	class Iterator {
		Node* current;
	public:
		Iterator() {
			current = NULL;
		}
		Iterator(Node* node) {
			current = node;
		}
		Iterator(Iterator& itr) {
			current = itr.current;
		}
		Iterator& operator++() {
			current = current->next;
			return *this;
		}
		Iterator& operator--() {
			current = current->prev;
			return *this;
		}
		bool operator==(Iterator const& itr)const {

			if (current == itr.current)
				return true;
			else return false;

		}
		bool operator!=(Iterator const& itr)const {

			if (current != itr.current)
				return true;
			else return false;

		}
		void operator*() {
			current->data.print();
		}
	};
	List<T>() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	List<T>(T d) {
		head = new Node;
		tail = new Node;
		Node* node = new Node(d);
		head->next = node;
		node->next = tail;
		tail->prev = node;
		node->prev = head;
		size = 1;
	}
	int getSize() {
		return size;
	}
	void insertAtEnd(T const element) {
		Node* node = new Node(element);
		node->next = tail;
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
		size++;
	}
	void DeleteAtStart() {
		Node* node = head->next;
		node->next->prev = head;
		head->next = node->next;
		delete node;
		size--;
	}
	void DeleteAtEnd() {
		Node* node = tail->prev;
		tail->prev->prev->next = tail;
		tail->prev = tail->prev->prev;
		delete node;
		size--;
	}
	Iterator begin() {
		Iterator itr(head);
		return itr;
	}
	Iterator end() {
		Iterator itr(tail);
		return itr;
	}
};

class UserInfo {
	string name; // data members of class UserInfo
	string gender;
	int Bmonth;
	int Bdate;
	int Byear;
	string astroSign;
	string fortune;
public:
	UserInfo() { // default constructor
		name = "";
		gender = "";
		Bmonth = 0;
		Bdate = 0;
		Byear = 0;
		astroSign = "";
		fortune = "";
	}
	UserInfo(string n, string g, int m, int d, int y, string* _fortune) { // parametrized constructor
		name = n;
		gender = g;
		Bmonth = m;
		Bdate = d;
		Byear = y;
		astroSign = computeZodiac(d, m);
		fortune = getFortune(_fortune, m);
	}
	// getters
	string getName() {
		return name;
	}
	string getGender() {
		return gender;
	}
	int getBmonth() {
		return Bmonth;
	}
	int getBdate() {
		return Bdate;
	}
	int getByear() {
		return Byear;
	}
	string getSign() {
		return astroSign;
	}
	string getMyFortune() {
		return fortune;
	}
	//Setters
	void setName(string n) {
		name = n;
	}
	void setGender(string g) {
		gender = g;
	}
	void setBmonth(int m) {
		Bmonth = m;
	}
	void setBdate(int d) {
		Bdate = d;
	}
	void setByear(int y) {
		Byear = y;
	}
	void print() { // Display data of class UserInfo
		cout << endl << "Name of Person = " << getName() << endl;
		cout << "Gender = " << getGender() << endl;
		cout << "Birth Info(Date-Month-Year) = " << getBdate() << "-" << getBmonth() << "-" << getByear() << endl;
		cout << "Your Zodiac Sign is " << getSign()<<". ";
		cout << getMyFortune() << endl;
	}
};

int main() { 
    string gender;  
    string name;

	List<UserInfo>Users;
	List<UserInfo>::Iterator itr;
	string fortune[12];
	computeFortune(fortune);
	bool check = false;

	while (!check) {
		system("cls");
		cout << " ______________________________________________________________________________________________________________________" << endl;
		cout << "|____________________________________________Welcome to: Fortune Tellers.com___________________________________________|" << endl << endl;
		//take input from user
		cout << endl << "Enter your name: ";
		cin >> name;

		cout << "Enter your gender(M/F): ";
		cin >> gender;

		//input related to birth
		cout << "Enter information related to your birth date:" << endl;
		cout << "	month(between 1-12 numbers): ";
		int month; // month of birth
		cin >> month;
		month = checkInput(month, 12); // check if input is valid

		cout << "	date of Birth: ";
		int date;
		cin >> date; // date of birth
		if (month == 2)
			date = checkInput(date, 28); // check if input is valid
		if (month % 2)
			date = checkInput(date, 31); // check if input is valid
		if (!(month % 2) && month != 2)
			date = checkInput(date, 30); // check if input is valid 

		cout << "	year of Birth: ";
		int year;
		cin >> year; // year of birth
		year = checkInput(year); // check if input is valid

		UserInfo user(name, gender, month, date, year, fortune);
		Users.insertAtEnd(user);

		cout << endl << "Computed Fortune is...";
		itr = Users.end();
		--itr;
		*(itr);

		char decide;
		bool check2 = false;
		while (check2 == false) {
			cout << endl << endl << "				Press 0 to exit.		OR" << endl;
			cout << "				press 1 to view previous record.		OR" << endl;
			cout << "				press 2 to view next record.		OR" << endl;
			cout << "				press any other key to compute Fortune Again." << endl;
			cout << endl << "						Enter selected number: ";
			cin >> decide;
			if (decide == '0') {
				check = true;
				check2 = true;
			}
			if (decide == '1') {
				--itr;
				if (itr != Users.begin()) {
					system("cls");
					*(itr);
				}
				else {
					cout << "						No PREVIOUS Record Found!" << endl;
					++itr;
				}
			}
			if (decide == '2') {
				++itr;
				if (itr != Users.end()) {
					system("cls");
					*(itr);
				}
				else {
					cout << "						No Next Record Found!" << endl;
					--itr;
				}
			}
			if (decide != '1' && decide != '2' && decide != '0')
				check2 = true;
		}

	}

	system("PAUSE");
	return 0;
}

