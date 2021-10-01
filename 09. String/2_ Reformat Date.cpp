/*
Problem Statement:

Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.

Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"

Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"

Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"

Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.

*/


// Driver code
#include "bits/stdc++.h"
#define endl "\n"

using namespace std;


string reformatDate(string date) {
	int length = date.length();
	string output;
	string year;
	string day;
	string month;
	year = date.substr(length - 4);
	size_t pos;
	if (date.find("th") != string::npos) {
		pos = date.find("th");
	}
	else if (date.find("st") != string::npos) {
		pos = date.find("st");
	}
	else if (date.find("rd") != string::npos) {
		pos = date.find("rd");
	}
	else if (date.find("nd") != string::npos) {
		pos = date.find("nd");
	}

	day = date.substr(0, pos);
	if (day.length() < 2) {
		day = "0" + day;
	}
	pos = date.find(" ") + 1;
	month = date.substr(pos, 3);
	if (month == "Jan") {
		month = "01";
	}
	else if (month == "Feb") {
		month = "02";
	}
	else if (month == "Mar") {
		month = "03";
	}
	else if (month == "Apr") {
		month = "04";
	}
	else if (month == "May") {
		month = "05";
	}
	else if (month == "Jun") {
		month = "06";
	}
	else if (month == "Jul") {
		month = "07";
	}
	else if (month == "Aug") {
		month = "08";
	}
	else if (month == "Sep") {
		month = "09";
	}
	else if (month == "Oct") {
		month = "10";
	}
	else if (month == "Nov") {
		month = "11";
	}
	else {
		month = "12";
	}
	return output = year + "-" + month + "-" + day;
}


int main() {

	int t;
	cin >> t;
	while (t--)
	{
		string date;
		cin >> date;
		cout << reformatDate(date) << endl;
	}
	return 0;
}


