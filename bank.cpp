#include <iostream>
using namespace std;


class BankAccount
{
    public:
    // onstruct with param
    BankAccount(string owner_in, double balance_in): owner(owner_in), balance(balance_in)
    {
        totalAccount ++;
    }

    // copy construct
    BankAccount(const BankAccount &BA): owner(BA.owner), balance(BA.balance)
    {
        totalAccount ++;
    }
    
    ~BankAccount()
    {
        cout << "ACCOUNT DESTROYED" << endl;

        totalAccount --;
    }

    // add balance
    void deposit(double amount)
    {
        if (amount <= 0)
            return ;
        balance += amount;
    }

    // withdraw the money
    void withdraw(double amount)
    {
        if (balance < amount)
        {
            cout << "U ain't got no money" << endl;
            return ;
        }

        balance -= amount;
    }

    // display the money
    void display()
    {
        cout << "Owner:" << owner << endl;
        cout << "Balance:" << balance << endl; 
    }
    
    void show()
    {
        
    }

    private:
        string owner;
        double balance; //余额

        static int totalAccount; // how many accounts are created totally
};

int BankAccount::totalAccount = 0;