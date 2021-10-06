// Vedansh Tandon
// 20118111
// Information Technology
// NIT Raipur


/* 
A basic c++ program to bulit a console appliaction for GYM MANAGEMENT SYSTEM
*/

#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// A userdefied datatype user which contains all the important properties of customers and staff
class user
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    // data members
public:
    char names[50];
    char phonenumber[12];
    char dob[10];
    float weights;
    float heights;
    float bmi;
    int account;
    char designation[15];
    int salary;
    char joining_date[14];
    int numberofmonths = 0;
    int bill = 0;
   
    // member methods
public:
    void join_member();
    void edit_member(char *p, char *b);
    void get_user_data();
    void display_all_users_data();
    void quit_member(char *pp, char *bb);
    void user_mode();
    void mode_portal();
    void normalweight();
    void underweight();
    void heavyweight();
    void exit_application();
    void search_details(char *pp, char *bb);
    float bmi_calculator(float wt = 1.1, float ht = 1.1)
    {
        float result = (wt * 10000.0) / (ht * ht);
        SetConsoleTextAttribute(color, 10);
        cout << "***********************************************************************************" << endl;
        cout << "**                                                                               **" << endl;
        cout << "**                         YOUR CURRENT BODY MASS INDEX (BMI) is         " << result << endl;
        cout << "**                                                                               **" << endl;
        cout << "***********************************************************************************" << endl;
        cout << "***********************************************************************************" << endl;
        cout << "**                                                                               **" << endl;
        cout << "**                                                                               **" << endl;

        if (result <= 18.5)
        {
            cout << "**                      BUDDY ! YOU ARE UNNERWEIGHT                              **" << endl;
        }
        else if (result <= 25 && result > 18.5)
        {
            cout << "**                      BUDDY ! YOU HAVE A HEALTHY WEIGHT                        **" << endl;
        }
        else if (result <= 30 && result > 25)
        {
            cout << "**                      BUDDY ! YOU ARE OVERWEIGHT                               **" << endl;
        }
        else
        {
            cout << "**                      BUDDY ! YOU ARE OBESE                                    **" << endl;
        }
        cout << "**                                                                               **" << endl;
        cout << "**                                                                               **" << endl;
        cout << "***********************************************************************************" << endl;
        cout << "***********************************************************************************" << endl;

        return result;
    }
    void admin_login();
    void add_staff();
    void search_staff(char *nn);
    void search_customer(char *nn, char *pp);
    void display_all_staff_details();
    void edit_staffmember(char *nn, char *pp);
    void get_staff_data();
    void delete_staff(char *nn, char *pp);
    void delete_customer(char *nn, char *pp);
};




// A function to delete customer record
void user::delete_customer(char *nn, char *pp)
{
    int a = 0;
    ifstream fin;
    ofstream fout;
    fin.open("database.txt", ios::in | ios::binary);
    fout.open("database1.txt", ios::out | ios::binary);
    fin.read((char *)this, sizeof(*this));
    SetConsoleTextAttribute(color, 14);
    while (!fin.eof())
    {
        if (!strcmp(nn, names) && !strcmp(pp, phonenumber))
        {
            SetConsoleTextAttribute(color, 10);
            cout << "***********************************************************************" << endl;
            cout << "**            YOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY             **" << endl;
            cout << "***********************************************************************" << endl;
            a = 1;
            SetConsoleTextAttribute(color, 14);
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    fout.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (a == 0)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS !! NO ACCOUNT FOUND                **" << endl;
        cout << "************************************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to delete staff record
void user::delete_staff(char *nn, char *pp)
{
    int a = 0;
    ifstream fin;
    ofstream fout;
    fin.open("staff.txt", ios::in | ios::binary);
    fout.open("staff1.txt", ios::out | ios::binary);
    fin.read((char *)this, sizeof(*this));
    SetConsoleTextAttribute(color, 14);
    while (!fin.eof())
    {
        if (!strcmp(nn, names) && !strcmp(pp, phonenumber))
        {
            SetConsoleTextAttribute(color, 10);
            cout << "***********************************************************************" << endl;
            cout << "**            YOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY             **" << endl;
            cout << "***********************************************************************" << endl;
            a = 1;
            SetConsoleTextAttribute(color, 14);
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    fout.close();

    remove("staff.txt");
    rename("staff1.txt", "staff.txt");

    if (a == 0)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS !! NO ACCOUNT FOUND                **" << endl;
        cout << "************************************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to get details of staff
void user::get_staff_data()
{
    SetConsoleTextAttribute(color, 13);
    cout << "*******************************************************************" << endl;
    cout << "*******************************************************************" << endl;
    cout << "**                                                               **" << endl;
    cout << "**         TO UPDATE STAFF DETAILS ENTER FOLLOWING DETAILS       **" << endl;
    cout << "**                                                               **" << endl;
    cout << "*******************************************************************" << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << endl;
    cout << "ENTER NEW PHONE NUMBER " << endl;
    cin >> phonenumber;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER NEW STAFF DATE OF BIRTH FORMAT (dd/mm/yyyy)" << endl;
    cin >> dob;
    cin.ignore();
    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "ENTER THE APPOINTTED POST OF STAFF MEMBER " << endl;
    cin >> designation;
    cout << endl;
    SetConsoleTextAttribute(color, 19);
    cout << "ENTER THE SALARY OF THE STAFF MEMBER" << endl;
    cin >> salary;
    cout << endl;
}





// A function to display all details of all staff
void user::display_all_staff_details()
{
    system("cls");
    user u1;
    ifstream fin;
    fin.open("staff.txt", ios::in | ios::binary);
    fin.seekg(0);
    fin.read((char *)this, sizeof(*this));
    if (!fin)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "**************************************************" << endl;
        cout << "**               FILE NOT FOUND                 **" << endl;
        cout << "**************************************************" << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
    }
    else
    {
        SetConsoleTextAttribute(color, 11);
        cout << "***********************************************************************" << endl;
        cout << "****                  LIST OF ALL STAFF MEMBERS                     ***" << endl;
        cout << "***********************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 10);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            SetConsoleTextAttribute(color, 10);
            cout << "************************************************************************" << endl;
            cout << "************************************************************************" << endl;
            cout << "***                                                                     " << endl;
            cout << "***              STAFF NAME             ::    " << names << endl;
            cout << "***                                                                     " << endl;
            cout << "***              PHONE NUMBER           ::    " << phonenumber << endl;
            cout << "***                                                                     " << endl;
            cout << "***              DATE OF BIRTH          ::    " << dob << endl;
            cout << "***                                                                     " << endl;
            cout << "***              DESIGNATION            ::    " << designation << endl;
            cout << "***                                                                     " << endl;
            cout << "***              SALARY                 ::    Rs-" << salary << endl;
            cout << "***                                                                     " << endl;
            cout << "************************************************************************" << endl;
            cout << "************************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 13);
            cout << "*************************************************************************************************************************************" << endl;
            cout << "*************************************************************************************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 10);
            fin.read((char *)this, sizeof(*this));
            SetConsoleTextAttribute(color, 14);
        }
        fin.close();
    }
    cout << endl;
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    system("cls");
}





// A function to search for details of a particular customer
void user::search_customer(char *nn, char *pp)
{
    user u1;
    int a = 0;
    ifstream fin;
    fin.open("database.txt", ios::in | ios::binary);
    fin.seekg(0);
    fin.read((char *)this, sizeof(*this));

    if (!fin)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "**************************************************" << endl;
        cout << "**               FILE NOT FOUND                 **" << endl;
        cout << "**************************************************" << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
    }
    else
    {
        system("cls");
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(names, nn) && !strcmp(pp, phonenumber))
            {

                SetConsoleTextAttribute(color, 10);
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << "***                                                                     " << endl;
                cout << "***              USER NAME              ::    " << names << endl;
                cout << "***                                                                     " << endl;
                cout << "***              PHONE NUMBER           ::    " << phonenumber << endl;
                cout << "***                                                                     " << endl;
                cout << "***              DATE OF BIRTH          ::    " << dob << endl;
                cout << "***                                                                     " << endl;
                cout << "***              WEIGHT                 ::    " << weights << endl;
                cout << "***                                                                     " << endl;
                cout << "***              HEIGHT                 ::    " << heights << endl;
                cout << "***                                                                     " << endl;
                cout << "***              ACCOUNT                ::    ";
                if (account == 1)
                {
                    cout << "SILVER MEMBERSHIP     FEES (Rs-2000) " << endl;
                }
                if (account == 2)
                {
                    cout << "GOLD MEMBERSHIP       FEES (Rs-3000)" << endl;
                }
                if (account == 3)
                {
                    cout << "DIAMOND MEMBERSHIP    FEES (Rs-4000)" << endl;
                }
                cout << "***                                                                     " << endl;
                cout << "***              JOINING DATE           ::    " << joining_date << endl;
                cout << "***                                                                     " << endl;
                cout << "***              NUMBER OF MONTHS       ::    " << numberofmonths << endl;
                cout << "***                                                                     " << endl;
                cout << "***              BILL                   ::    Rs" << bill << endl;
                cout << "***                                                                     " << endl;
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(color, 13);
                cout << "****************************************************************************************************************************************************" << endl;
                cout << "*****************************************************************************************************************************************************" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(color, 10);
                
                a = 1;
            }
            fin.read((char *)this, sizeof(*this));
        }
        SetConsoleTextAttribute(color, 14);
        fin.close();
        if (a == 0)
        {
            SetConsoleTextAttribute(color, 12);
            cout << "************************************************************************" << endl;
            cout << "**                 INVALID DETAILS NO ACCOUNT FOUND                   **" << endl;
            cout << "************************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 14);
        }
    }
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to search for details of a particular staff
void user::search_staff(char *nn)
{
    user u1;
    int a = 0;
    ifstream fin;
    fin.open("staff.txt", ios::in | ios::binary);
    fin.seekg(0);
    fin.read((char *)this, sizeof(*this));

    if (!fin)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                       FILE NOT FOUND                               **" << endl;
        cout << "************************************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    else
    {
        system("cls");
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(names, nn))
            {
                SetConsoleTextAttribute(color, 11);
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << "***                                                                     " << endl;
                cout << "***              STAFF NAME             ::    " << names << endl;
                cout << "***                                                                     " << endl;
                cout << "***              PHONE NUMBER           ::    " << phonenumber << endl;
                cout << "***                                                                     " << endl;
                cout << "***              DATE OF BIRTH          ::    " << dob << endl;
                cout << "***                                                                     " << endl;
                cout << "***              DESIGNATION            ::    " << designation << endl;
                cout << "***                                                                     " << endl;
                cout << "***              SALARY                 ::   Rs  " << salary << endl;
                cout << "***                                                                     " << endl;
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(color, 13);
                cout << "****************************************************************************************************************************************************" << endl;
                cout << "*****************************************************************************************************************************************************" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                a = 1;
                SetConsoleTextAttribute(color, 14);
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        if (a == 0)
        {
            SetConsoleTextAttribute(color, 12);
            cout << "************************************************************************" << endl;
            cout << "**                 INVALID DETAILS NO ACCOUNT FOUND                   **" << endl;
            cout << "************************************************************************" << endl;
            SetConsoleTextAttribute(color, 14);
        }
    }
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to add a new staff in staff.txt file
void user::add_staff()
{
    user u1;
    int flag = 0;
    system("cls");
    SetConsoleTextAttribute(color, 14);
    cout << "*************************************************************************************" << endl;
    cout << "***                TO ADD A NEW STAFF MEMBER ENTER FOLLOWING DETAILS              ***" << endl;
    cout << "*************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    cout << "ENTER STAFF NAME" << endl;
    cin >> names;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER STAFF PHONE NUMBER " << endl;
    cin >> phonenumber;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "ENTER STAFF DATE OF BIRTH FORMAT (dd/mm/yyyy)" << endl;
    cin >> dob;
    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "ENTER THE APPOINTTED POST OF STAFF MEMBER " << endl;
    cin >> designation;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "ENTER THE SALARY OF THE STAFF MEMBER" << endl;
    cin >> salary;
    cout << endl;
    cout << endl;
    cout << endl;
    system("cls");
    SetConsoleTextAttribute(color, 10);
    cout << "***************************************************************************************************" << endl;
    cout << "**               BUDDY !  YOUR GYM STAFF ACCOUNT HAS BEEN CREATED SUCCESSFULLY                   **" << endl;
    cout << "***************************************************************************************************" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**               YOUR GYM MEMBER    ID  " << phonenumber << " KEEP IT SAFE WITH YOU                         **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "***************************************************************************************************" << endl;
    SetConsoleTextAttribute(color, 13);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    ofstream fout;
    fout.open("staff.txt", ios::out | ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to edit the details of staff
void user::edit_staffmember(char *nn, char *pp)
{
    int a = 0;
    ifstream fin;
    ofstream fout;
    fin.open("staff.txt", ios::in | ios::binary);
    fout.open("staff1.txt", ios::out | ios::binary);
    fin.read((char *)this, sizeof(*this));
    system("cls");
    while (!fin.eof())
    {
        if (!strcmp(names, nn) && !strcmp(pp, phonenumber))
        {

            get_staff_data();
            cout << endl;
            SetConsoleTextAttribute(color, 10);
            cout << "***********************************************************************" << endl;
            cout << "**            YOUR ACCOUNT HAS BEEN UPDATED SUCCESSFULLY             **" << endl;
            cout << "***********************************************************************" << endl;
            SetConsoleTextAttribute(color, 14);
            a = 1;
            fout.write((char *)this, sizeof(*this));
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    fout.close();

    remove("staff.txt");
    rename("staff1.txt", "staff.txt");

    if (a == 0)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS !! NO ACCOUNT FOUND                **" << endl;
        cout << "************************************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function for the admin login portal
void user::admin_login()
{
    user u1;
    char nm[60];
    char pn[20];
    char pp[20];
    char bb[10];
    int choice = 99;
    system("cls");
    SetConsoleTextAttribute(color, 13);
    cout << "***********************************************************" << endl;
    cout << "***********************************************************" << endl;
    cout << "**                                                       **" << endl;
    cout << "**            WELCOME   TO  THE  ADMIN  PORTAL           **" << endl;
    cout << "**                                                       **" << endl;
    cout << "***********************************************************" << endl;
    cout << "**                                                       **" << endl;
    cout << "**      'YOUR HEALTH IS AN INVESTMENT NOT AN EXPENSE'    **" << endl;
    cout << "**                                                       **" << endl;
    cout << "***********************************************************" << endl;
    cout << "***********************************************************" << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER 1 ::  TO ADD STAFF MEMBER " << endl;
    cout << "ENTER 2 ::  TO SEARCH STAFF " << endl;
    cout << "ENTER 3 ::  TO SEARCH CUSTOMER " << endl;
    cout << "ENTER 4 ::  TO DISPLAY ALL STAFF DETAILS" << endl;
    cout << "ENTER 5 ::  TO DISPLAY ALL CUSTOMERS DETAILS" << endl;
    cout << "ENTER 6 ::  TO UPDATE STAFF MEMBER DETAILS" << endl;
    cout << "ENTER 7 ::  TO DELETE STAFF MEMBER ACCOUNT" << endl;
    cout << "ENTER 8 ::  TO DELETE CUSTOMER ACCOUNT" << endl;
    cout << "ENTER 9 ::  TO LOG OUT ADMIN PORTAL" << endl;
    cout << "ENTER YOUR CHOICE" << endl;
    cin >> choice;
    SetConsoleTextAttribute(color, 14);
    switch (choice)
    {
    case 1:
    {
        u1.add_staff();
        u1.admin_login();
        break;
    }
    case 2:
    {
        cout << "ENTER STAFF NAME" << endl;
        cin >> nm;
        cout << endl;
        u1.search_staff(nm);
        u1.admin_login();
        break;
    }
    case 3:
    {
        cout << " ENTER CUSTOMER NAME  " << endl;
        cin >> nm;
        cout << "ENTER REGISTERED PHONENUMBER OE GYM MEMBER ID " << endl;
        cin >> pp;
        cout << endl;
        u1.search_customer(nm, pp);
        u1.admin_login();
        break;
    }
    case 4:
    {
        system("cls");
        cout << endl;
        u1.display_all_staff_details();
        u1.admin_login();
        break;
    }
    case 5:
    {
        system("cls");
        cout << endl;
        u1.display_all_users_data();
        u1.admin_login();
        break;
    }
    case 6:
    {
        system("cls");
        cout << "ENTER STAFF NAME " << endl;
        cin >> nm;
        cout << endl;
        cout << "ENTER STAFF PHONENUMBER " << endl;
        cin >> pp;
        cout << endl;
        u1.edit_staffmember(nm, pp);
        u1.admin_login();
        break;
    }
    case 9:
    {
        system("cls");
        u1.mode_portal();
        break;
    }
    case 7:
    {
        cout << "ENTER STAFF NAME" << endl;
        cin >> nm;
        cout << endl;
        cout << "ENTER STAFF PHONENUMBER " << endl;
        cin >> pp;
        cout << endl;
        u1.delete_staff(nm, pp);
        u1.admin_login();
        break;
    }
    case 8:
    {

        cout << "ENTER CUSTOMER NAME" << endl;
        cin >> nm;
        cout << endl;
        cout << "ENTER CUSTOMER PHONENUMBER " << endl;
        cin >> pp;
        cout << endl;
        u1.delete_customer(nm, pp);
        u1.admin_login();
        break;
    }
    default:
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID CHOICES                                    **" << endl;
        cout << "************************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
        getch();
        u1.admin_login();
    }
    }
}





// A function to add a new customer to the gym
void user::join_member()
{
    system("cls");
    SetConsoleTextAttribute(color, 14);
    cout << "ENTER YOUR NAME" << endl;
    cin >> names;
    cin.ignore();
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER YOUR PHONE NUMBER" << endl;
    cin >> phonenumber;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    cout << "ENTER YOUR WEIGHT  IN Kgs" << endl;
    cin >> weights;
    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "ENTER YOUR HEIGHT  in cm" << endl;
    cin >> heights;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER YOUR DATE OF BIRTH     FORMAT(dd/mm/yyyy)  " << endl;
    cin >> dob;
    cout << endl;
    cout << endl;
    int flag = 0, ch;
    SetConsoleTextAttribute(color, 14);
    while (flag == 0)
    {
        cout << "ENTER 1 TO JOIN   SILVER    MEMEBERSHIP   ->>>> FEES ( Rs 2000 /- MONTH )" << endl;
        cout << "ENTER 2 TO JOIN   GOLD      MEMEBERSHIP   ->>>> FEES ( Rs 3000 /- MONTH )" << endl;
        cout << "ENTER 3 TO JOIN   DIAMOND   MEMEBERSHIP   ->>>> FEES ( Rs 4000 /- MONTH )" << endl;
        cin >> ch;
        if (ch == 1)
        {
            account = 1;
            flag = 1;
        }
        else if (ch == 2)
        {
            account = 2;
            flag = 1;
        }
        else if (ch == 3)
        {
            account = 3;
            flag = 1;
        }
        else
        {
            SetConsoleTextAttribute(color, 12);
            cout << "************************************************************************" << endl;
            cout << "**                 INVALID CHOICE                                     **" << endl;
            cout << "************************************************************************" << endl;
            SetConsoleTextAttribute(color, 14);
        }
    }
    SetConsoleTextAttribute(color, 13);
    cout << endl;
    cout << " ENTER JOINING DATE " << endl;
    cin >> joining_date;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER NUMBER OF MONTHS FOR SUBSCRIPTION" << endl;
    cin >> numberofmonths;
    cout << endl;
    if (account == 1)
    {
        bill = 2000 * numberofmonths;
    }
    if (account == 2)
    {
        bill = 3000 * numberofmonths;
    }
    if (account == 3)
    {
        bill = 4000 * numberofmonths;
    }
    SetConsoleTextAttribute(color, 14);
    system("cls");
    SetConsoleTextAttribute(color, 10);
    cout << "***************************************************************************************************" << endl;
    cout << "**               TOTAL BILL =                Rs " << bill << endl;
    cout << "***************************************************************************************************" << endl;
    SetConsoleTextAttribute(color, 13);
    cout << "***************************************************************************************************" << endl;
    cout << "**               PAY YOUR BILL AMOUNT TO PROCEED FURTHER                                         **" << endl;
    cout << "***************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    cout << endl;
    cout << endl;
    system("cls");
    SetConsoleTextAttribute(color, 10);
    cout << "***************************************************************************************************" << endl;
    cout << "**               BUDDY !  YOUR GYM WORLD ACCOUNT HAS BEEN CREATED SUCCESSFULLY                   **" << endl;
    cout << "***************************************************************************************************" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**               YOUR GYM MEMBER    ID  " << phonenumber << " KEEP IT SAFE WITH YOU                         **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "**                                                                                               **" << endl;
    cout << "***************************************************************************************************" << endl;
    SetConsoleTextAttribute(color, 14);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    system("cls");
    ofstream fout;
    fout.open("database.txt", ios::out | ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
    bmi = bmi_calculator(weights, heights);
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to search the details of a particular customer
void user::search_details(char *pp, char *bb)
{
    user u1;
    int a = 0;
    ifstream fin;
    fin.open("database.txt", ios::in | ios::binary);
    fin.seekg(0);
    fin.read((char *)this, sizeof(*this));

    if (!fin)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "**************************************************" << endl;
        cout << "**               FILE NOT FOUND                 **" << endl;
        cout << "**************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    else
    {

        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(dob, bb) && !strcmp(pp, phonenumber))
            {
                SetConsoleTextAttribute(color, 10);
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << "***                                                                     " << endl;
                cout << "***              USER NAME              ::    " << names << endl;
                cout << "***                                                                     " << endl;
                cout << "***              PHONE NUMBER           ::    " << phonenumber << endl;
                cout << "***                                                                     " << endl;
                cout << "***              DATE OF BIRTH          ::    " << dob << endl;
                cout << "***                                                                     " << endl;
                cout << "***              WEIGHT                 ::    " << weights << endl;
                cout << "***                                                                     " << endl;
                cout << "***              HEIGHT                 ::    " << heights << endl;
                cout << "***                                                                     " << endl;
                cout << "***              ACCOUNT                ::    ";
                if (account == 1)
                {
                    cout << "SILVER MEMBERSHIP     FEES (Rs-2000) " << endl;
                }
                if (account == 2)
                {
                    cout << "GOLD MEMBERSHIP       FEES (Rs-3000)" << endl;
                }
                if (account == 3)
                {
                    cout << "DIAMOND MEMBERSHIP    FEES (Rs-4000)" << endl;
                }
                cout << "***                                                                     " << endl;
                cout << "***              JOINING DATE             ::    " << joining_date << endl;
                cout << "***                                                                     " << endl;
                cout << "***              NUMBER OF MONTHS         ::    " << numberofmonths << endl;
                cout << "***                                                                     " << endl;
                cout << "***              BILL                     ::    " << bill << endl;
                cout << "***                                                                     " << endl;
                cout << "************************************************************************" << endl;
                cout << "************************************************************************" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(color, 13);
                cout << "****************************************************************************************************************************************************" << endl;
                cout << "*****************************************************************************************************************************************************" << endl;
                SetConsoleTextAttribute(color, 10);
                a = 1;
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        if (a == 0)
        {
            SetConsoleTextAttribute(color, 12);
            cout << "************************************************************************" << endl;
            cout << "**                 INVALID DETAILS !! NO ACCOUNT FOUND                 **" << endl;
            cout << "************************************************************************" << endl;
        }
    }
    SetConsoleTextAttribute(color, 14);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    u1.user_mode();
}





// A function for deleting the record of a particular function
void user::quit_member(char *pp, char *bb)
{
    int a = 0;
    ifstream fin;
    ofstream fout;
    fin.open("database.txt", ios::in | ios::binary);
    fout.open("database1.txt", ios::out | ios::binary);
    fin.read((char *)this, sizeof(*this));
    SetConsoleTextAttribute(color, 14);
    while (!fin.eof())
    {
        if (!strcmp(bb, dob) && !strcmp(pp, phonenumber))
        {
            SetConsoleTextAttribute(color, 10);
            cout << "***********************************************************************" << endl;
            cout << "**            YOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY             **" << endl;
            cout << "***********************************************************************" << endl;
            a = 1;
            SetConsoleTextAttribute(color, 14);
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    fout.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (a == 0)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS !! NO ACCOUNT FOUND                **" << endl;
        cout << "************************************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to display all details of all customers
void user::display_all_users_data()
{
    system("cls");
    ifstream fin;
    fin.open("database.txt", ios::in | ios::binary);
    fin.seekg(0);
    fin.read((char *)this, sizeof(*this));

    if (!fin)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "**************************************************" << endl;
        cout << "**               FILE NOT FOUND                 **" << endl;
        cout << "**************************************************" << endl;
        SetConsoleTextAttribute(color, 14);
    }
    else
    {

        SetConsoleTextAttribute(color, 11);
        cout << endl;
        cout << endl;
        cout << "***************************************************************************" << endl;
        cout << "****                     LIST   OF ALL CUSTOMERS DETAILS               ****" << endl;
        cout << "***************************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 10);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            SetConsoleTextAttribute(color, 10);
            cout << "************************************************************************" << endl;
            cout << "************************************************************************" << endl;
            cout << "***                                                                     " << endl;
            cout << "***              USER NAME              ::    " << names << endl;
            cout << "***                                                                     " << endl;
            cout << "***              PHONE NUMBER           ::    " << phonenumber << endl;
            cout << "***                                                                     " << endl;
            cout << "***              DATE OF BIRTH          ::    " << dob << endl;
            cout << "***                                                                     " << endl;
            cout << "***              WEIGHT                 ::    " << weights << endl;
            cout << "***                                                                     " << endl;
            cout << "***              HEIGHT                 ::    " << heights << endl;
            cout << "***                                                                     " << endl;
            cout << "***              ACCOUNT                ::    ";
            if (account == 1)
            {
                cout << "SILVER MEMBERSHIP     FEES (Rs-2000) " << endl;
            }
            if (account == 2)
            {
                cout << "GOLD MEMBERSHIP       FEES (Rs-3000)" << endl;
            }
            if (account == 3)
            {
                cout << "DIAMOND MEMBERSHIP    FEES (Rs-4000)" << endl;
            }
            cout << "***                                                                     " << endl;
            cout << "***              JOINING DATE           ::    " << joining_date << endl;
            cout << "***                                                                    " << endl;
            cout << "***              NUMBER OF MONTHS       ::    " << numberofmonths << endl;
            cout << "***                                                                     " << endl;
            cout << "***              BILL                   ::    " << bill << endl;
            cout << "***                                                                     " << endl;
            cout << "************************************************************************" << endl;
            cout << "************************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 13);
            cout << "****************************************************************************************************************************************************" << endl;
            cout << "*****************************************************************************************************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 10);
            fin.read((char *)this, sizeof(*this));
            SetConsoleTextAttribute(color, 14);
        }
        fin.close();
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    system("cls");
    SetConsoleTextAttribute(color, 14);
}





// A function to get all data from a customer
void user::get_user_data()
{
    system("cls");
    SetConsoleTextAttribute(color, 14);
    cout << "ENTER YOUR   NEW NAME" << endl;
    cin >> names;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER YOUR  WEIGHT  IN Kgs" << endl;
    cin >> weights;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    cout << "ENTER YOUR HEIGHT  in cm" << endl;
    cin >> heights;
    cout << endl;

    bmi = (weights * 10000) / (heights * heights);

    SetConsoleTextAttribute(color, 14);
}





// A function to edit the record details of a particular customer
void user::edit_member(char *p, char *b)
{
    user u1;
    int a = 0;
    ifstream fin;
    ofstream fout;
    fin.open("database.txt", ios::in | ios::binary);
    fout.open("database1.txt", ios::out | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        if (!strcmp(dob, b) && !strcmp(p, phonenumber))
        {

            get_user_data();
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 10);
            cout << "************************************************************************" << endl;
            cout << "**        YOUR ACCOUNT DETAILS HAS BEEN UPDATED SUCCESSFULLY          **" << endl;
            cout << "************************************************************************" << endl;
            a = 1;
            SetConsoleTextAttribute(color, 14);
            fout.write((char *)this, sizeof(*this));
        }
        else
        {
            fout.write((char *)this, sizeof(*this));
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    fout.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (a == 0)
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS NO ACCOUNT FOUND                   **" << endl;
        cout << "************************************************************************" << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    SetConsoleTextAttribute(color, 14);
}





// A function to display tips for underweight persons
void user::underweight()
{
    system("cls");
    SetConsoleTextAttribute(color, 11);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "**                   HEY ! BUDDY LET US DISCUSS SOME PLANS TO GAIN MAINTAIN                    **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   1 : Eat calorie dense food                                                **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   2 : Consume heavy carbohydrates                                           **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   3 : Consume a protien source with every meal                              **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   4 : Add healthy fats to your diet                                         **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   5 : Take weight gain supplements                                          **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   6 : Eliminate stress                                                      **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   7 : Have enough sleep                                                     **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                   8 : Stay motivated to gain some weight                                    **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    SetConsoleTextAttribute(color, 13);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to display tips for normalweight people
void user::normalweight()
{
    system("cls");
    SetConsoleTextAttribute(color, 11);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  HEY ! BUDDY LET US DISCUSS SOME PLAN TO MAINTAIN A HEALTHY WEIGHT          **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  1 : Be physically active as you can be                                     **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  2 : Track what you eat                                                     **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  3 : Drink more water                                                       **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  4 : Eliminate stress                                                       **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  5 : Have enough sleep                                                      **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "**                  6 : Stay motivated to maintain weight                                      **" << endl;
    cout << "**                                                                                             **" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "*************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 13);
    SetConsoleTextAttribute(color, 13);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}





// A function to display tips for heavyweight people
void user::heavyweight()
{
    system("cls");
    SetConsoleTextAttribute(color, 11);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "************************************************************************************" << endl;
    cout << "************************************************************************************" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             HEY ! BUDDY LET US DISCUSS SOME PLANS TO LOSE WEIGHT               **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             1 : Be physically active as you can be                             **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             2 : Track what you eat                                             **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             3 : Take weight loss friendly food                                 **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             4 : Eat soluble fiber                                              **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             5 : Avoid eating food containing fats and carbohydrates            **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             6 : Do workout to burn your calories                               **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "**             7 : Stay motivated to maintain weight                              **" << endl;
    cout << "**                                                                                **" << endl;
    cout << "************************************************************************************" << endl;
    cout << "************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
    SetConsoleTextAttribute(color, 13);
    SetConsoleTextAttribute(color, 13);
}





// A function to exit application
void user::exit_application()
{
    system("cls");
    SetConsoleTextAttribute(color, 14);
    cout << "*********************************************************************" << endl;
    cout << "*********************************************************************" << endl;
    cout << "**                                                                 **" << endl;
    cout << "**            THANK YOU FOR USING OUR APPLICATION                  **" << endl;
    cout << "**                                                                 **" << endl;
    cout << "*********************************************************************" << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
    getch();
}




// A function to take control to user mode portal
void user::user_mode()  
{
    user u1;
    char k[12];
    char birth[10];
    float hh = 0.0;
    char nm[50];
    int choice = 55;
    system("cls");
    system("cls");
    SetConsoleTextAttribute(color, 14);
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << "**                                                     **" << endl;
    cout << "**                                                     **" << endl;
    cout << "**          WELCOME   TO  THE  USER  PORTAL            **" << endl;
    cout << "**                                                     **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << "**                                                     **" << endl;
    cout << "**    'YOUR HEALTH IS AN INVESTMENT NOT AN EXPENSE'    **" << endl;
    cout << "**                                                     **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "ENTER 1  :  TO JOIN GYM" << endl;
    cout << "ENTER 2  :  TO EDIT YOUR PROFILES" << endl;
    cout << "ENTER 3  :  TO DELETE ACCOUNT" << endl;
    cout << "ENTER 4  :  TO CALCULATE YOUR BODY MASS INDEX (BMI) " << endl;
    cout << "ENTER 5  :  READ SUGGESTIONS FOR UNDERWEIGHT PEOPLE " << endl;
    cout << "ENTER 6  :  READ SUGGESTIONS FOR HEALTHY WEIGHT PEOPLE" << endl;
    cout << "ENTER 7  :  READ SUGGESTIONS FOR HEAVY WEIGHT OR OBSESSE PEOPLE" << endl;
    cout << "ENTER 8  :  TO GO BACK TO MAIN MENU PORTAL" << endl;
    cout << "ENTER 9  :  TO SEARCH FOR YOUR PROFILE DETAILS" << endl;
    cout << "ENTER 10 :  TO EXIT THIS APPLICATION" << endl;
    cout << "ENTER YOU CHOICE " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        u1.join_member();
        u1.user_mode();
        break;
    }
    case 2:
    {
        cout << "ENTER YOUR REGISTERED MEMBER ID OR PHONE NUMBER" << endl;
        cin >> k;
        cout << endl;
        cout << "ENTER YOUR DATE OF BIRTH  FORMAT (dd/mm/yyyy)  " << endl;
        cin >> birth;
        cout << endl;
        u1.edit_member(k, birth);
        u1.user_mode();
        break;
    }
    case 3:
    {
        cout << "ENTER YOUR REGISTERED MEMBER ID OR PHONE NUMBER" << endl;
        cin >> k;
        cout << endl;
        cout << "ENTER YOUR NAME   " << endl;
        cin >> nm;
        cout << endl;
        u1.delete_customer(nm, k);
        u1.user_mode();
        break;
    }
    case 4:
    {
        system("cls");
        float wt, ht;
        SetConsoleTextAttribute(color, 14);
        cout << "*******************************************************************************" << endl;
        cout << "*******************************************************************************" << endl;
        cout << "**                                                                           **" << endl;
        cout << "**                                                                           **" << endl;
        cout << "**    TO CALCULATE YOUR BODY MASS INDEX WE WANT KNOW FOLLOWING DETAILS       **" << endl;
        cout << "**                                                                           **" << endl;
        cout << "**                                                                           **" << endl;
        cout << "*******************************************************************************" << endl;
        cout << "*******************************************************************************" << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "ENTER YOUR WEIGHT IN Kgs" << endl;
        cin >> wt;
        cout << endl;
        cout << "ENTER YOUR HEIGHT IN cm" << endl;
        cin >> ht;
        system("cls");
        float hh = bmi_calculator(wt, ht);
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
        getch();
        SetConsoleTextAttribute(color, 14);
        u1.user_mode();
        break;
    }

    case 5:
    {
        u1.underweight();
        u1.user_mode();
        break;
    }

    case 6:
    {
        u1.normalweight();
        u1.user_mode();
        break;
    }

    case 7:
    {
        u1.heavyweight();
        u1.user_mode();
        break;
    }

    case 8:
    {
        u1.mode_portal();
        break;
    }
    case 9:
    {
        cout << "ENTER YOUR REGISTERED MEMBER ID OR PHONE NUMBER" << endl;
        cin >> k;
        cout << endl;
        cout << "ENTER YOUR DATE OF BIRTH  FORMAT (dd/mm/yyyy)   " << endl;
        cin >> birth;
        cout << endl;
        u1.search_details(k, birth);
        break;
    }

    case 10:
    {
        SetConsoleTextAttribute(color, 11);
        u1.exit_application();
        break;
    }
    default:
    {

        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS NO ACCOUNT FOUND                   **" << endl;
        cout << "************************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
        getch();
        u1.user_mode();
    }
    }
}




// A function to ask for mode portal menu
void user::mode_portal()
{
    user u1;
    int choice;
    SetConsoleTextAttribute(color, 11);
    system("cls");
    system("cls");
    cout << "**********************************************************" << endl;
    cout << "**********************************************************" << endl;
    cout << "****                                                  ****" << endl;
    cout << "****                                                  ****" << endl;
    cout << "****       WELCOME   TO   A   HEALTHY    WORLD        ****" << endl;
    cout << "****           FROM UNHEALTHY -> HEALTHY              ****" << endl;
    cout << "****              FROM  UNFIT  ->  FIT                ****" << endl;
    cout << "****                                                  ****" << endl;
    cout << "**********************************************************" << endl;
    cout << "**********************************************************" << endl;
    cout << "****                                                  ****" << endl;
    cout << "****                                                  ****" << endl;
    cout << "****   'YOUR HEALTH IS AN INVESTMENT NOT AN EXPENSE'  ****" << endl;
    cout << "****                                                  ****" << endl;
    cout << "****                                                  ****" << endl;
    cout << "**********************************************************" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 14);

    cout << "ENTER 1 :: TO USE THIS APPLICATION IN USER MODE" << endl;
    cout << "ENTER 2 :: TO USE THIS APPLICATION IN ADMIN MODE" << endl;
    cout << "ENTER 3 :: TO EXIT THIS APPLICATION" << endl;
    cout << "ENTER YOUR CHOICE " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        u1.user_mode();
        break;
    }
    case 2:
    {
        system("cls");
        string admin;
        string password;

        SetConsoleTextAttribute(color, 11);
        cout << "*********************************************************************************" << endl;
        cout << "*********************************************************************************" << endl;
        cout << "****                                                                         ****" << endl;
        cout << "****                                                                         ****" << endl;
        cout << "****      TO GET ACCESS TO ADMIN PORTAL YOU MUST ENTER FOLLOWING DETAILS     ****" << endl;
        cout << "****                                                                         ****" << endl;
        cout << "****                                                                         ****" << endl;
        cout << "*********************************************************************************" << endl;
        cout << "*********************************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "ENTER ADMIN NAME" << endl;
        cout << endl;
        cin >> admin;
        cout << endl;
        SetConsoleTextAttribute(color, 13);
        cout << "ENTER ADMIN PORTAL PASSWORD " << endl;
        cout << endl;
        cin >> password;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        system("cls");

        if (admin == "supreme_power" && password == "give_access")
        {
            system("cls");
            SetConsoleTextAttribute(color, 10);
            cout << "**************************************************************" << endl;
            cout << "**************************************************************" << endl;
            cout << "****                                                      ****" << endl;
            cout << "****                                                      ****" << endl;
            cout << "****       ADMIN PORTAL    ::::::::      ACCESS GRANTED   ****" << endl;
            cout << "****                                                      ****" << endl;
            cout << "****                                                      ****" << endl;
            cout << "**************************************************************" << endl;
            cout << "**************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 14);
            cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
            SetConsoleTextAttribute(color, 14);
            getch();
            u1.admin_login();
        }
        else
        {
            system("cls");
            SetConsoleTextAttribute(color, 12);
            cout << "***************************************************************" << endl;
            cout << "***************************************************************" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****   ADMIN PORTAL                  ACCESS DENIED         ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "***************************************************************" << endl;
            cout << "***************************************************************" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****             PLEASE ENTER CORRECT ADMIN DETAILS        ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "****                                                       ****" << endl;
            cout << "***************************************************************" << endl;
            cout << "***************************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(color, 14);
            cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
            SetConsoleTextAttribute(color, 14);
            getch();
            u1.mode_portal();
        }
        break;
    }
    case 3:
    {
        u1.exit_application();
        break;
    }
    default:
    {
        SetConsoleTextAttribute(color, 12);
        cout << "************************************************************************" << endl;
        cout << "**                 INVALID DETAILS NO ACCOUNT FOUND                   **" << endl;
        cout << "************************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "PRESS ANY KEY TO CONTINUE.................................." << endl;
        getch();
        SetConsoleTextAttribute(color, 14);
        u1.mode_portal();
    }
    }
}





// main menu function
int main()
{
    user u1;
    u1.mode_portal();
    return 0;
}
