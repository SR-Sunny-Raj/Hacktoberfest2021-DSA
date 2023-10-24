#include <bits/stdc++.h>
using namespace std;

unordered_map<long,float> mp;
class Manager;
class User
{
    string name;
    float balance;
    float t;
    long acno;
    static long AccountNumber;
    public:
    

    void openAccount()
    {
        cout<<"Enter name\n";
        cin>>name;

        cout<<"Enter initial amount\n";
        cin>>balance;

        acno=AccountNumber;

        mp.insert({acno,balance});

        cout<<"Account is created\n";
        cout<<"Account Number: "<<AccountNumber<<endl;
        cout<<"Total balance "<<balance<<endl;

        AccountNumber++;


    }

    bool check(long a)
    {
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->first==a)
            {
                return true;
                break;
            }
        }
        return false;
    }

    void findAc(long a)
    {
       for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->first==a)
            {

                break;
            }
        }
    }

    void deposit()
    {
        cout<<"enter account no.\n";
        long ac;
        cin>>ac;
       if(check(ac))
       {

        cout<<"Enter amount to deposit\n";
        cin>>t;
        balance+=t;


        cout<<"Account Number: "<<acno<<endl;
        cout<<"Total balance "<<balance<<endl;
        mp[ac]=balance;
       }
       else
         cout<<"invalid account no.\n";

    }
    void withdraw()
    {
        cout<<"enter account no.\n";
        long ac;
        cin>>ac;
        if(check(ac))
        {
            cout<<"Enter amount to withdraw: \n";
        cin>>t;
        balance-=t;


        cout<<"Account Number: "<<acno<<endl;
        cout<<"Total balance: "<<balance<<endl;
        mp[ac]=balance;
        }
        else
            cout<<"invalid account no.\n";
    }
    void display()
    {
        cout<<"enter account no.\n";
        long ac;
        cin>>ac;
        if(check(ac))
        {
            cout<<"Account Number: "<<ac<<endl;
            cout<<"Total balance "<<mp[ac]<<endl;
        }
        else
            cout<<"invalid account no.\n";
    }

   
};

class Manager
{
    int password;


public:
    void setPassword(int password)
    {
        this->password=password;
    }

    bool isTrue(int password)
    {
        if(this->password==password)
            return true;
        else
            return false;
    }

    
    void show()
    {
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            cout<<"Account no.: "<<it->first<<"   Balance: "<<it->second<<endl;
        }
    }


};

long User::AccountNumber=1;


int main()
{
    cout<<"Create password for manager: ";
    Manager m;
    int p;
    cin>>p;
    m.setPassword(p);

    int num;

    do{
         cout<<"Enter\n1 for manager \n2 for User\n3 to quit \n:";

          cin>>num;

          User u;

    if(num==1)
    {
        int choice;

       do
       {
           cout<<"enter your password\n";
           int t;cin>>t;

           if(m.isTrue(t))
         {
        cout<<"\nSelect one option ";
        cout<<"\n1.Increase or Decrease Rate of interst";
        cout<<"\n2.Close an Account";
        cout<<"\n3.Show All Accounts";
        cout<<"\n4.Quit for manager\n:";

           cin>>choice;
           switch(choice)
           {
              case 1:cout<<"Enter roi \n";
                    int roi;
                    cin>>roi;
                    for(auto it=mp.begin();it!=mp.end();it++)
                    {
                        it->second=it->second+((it->second*roi)/100);
                    }
                    for(auto it=mp.begin();it!=mp.end();it++)
                        {
                            cout<<"Account no.: "<<it->first<<" Balance: "<<it->second<<endl;
                        }
                    break;



              case 2:cout<<"Enter account no. to be deleted\n";
                     int A;cin>>A;
                     mp.erase(A);
                     cout<<"Account is deleted succesfully\n";
                     break;

              case 3:m.show();
                     break;
           }
         }

         else
        cout<<"invalid password\n";

       }while(choice!=4);


    }
    if(num==2)
    {
        int option;
       do{
        cout<<"\n Select one option ";
        cout<<"\n 1.Open an Account";
        cout<<"\n 2.Balance Enquiry";
        cout<<"\n 3.Deposit";
        cout<<"\n 4.Withdrawal";
        cout<<"\n 5.Quit for user\n";

        cin>>option;
        switch(option)
        {
            case 1:u.openAccount();
                   break;

            case 2:u.display();
                   break;

            case 3:u.deposit();
                   break;

            case 4:u.withdraw();
                   break;
        }
      }while(option!=5);

       }

    }while(num!=3);

    return 0;

}

