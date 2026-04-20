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
                cout << "U ain't got no money :( " << endl;
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

        static void getTotalAccount(); // show how many account is constructed totally

    private:
        string owner;
        double balance; //余额

        static int totalAccount;      // how many accounts are created totally
};


int BankAccount::totalAccount = 0;
void BankAccount::getTotalAccount() { cout << "totalAccount=" << totalAccount << endl; }


int main()
{
    // ====== just for test =======
    BankAccount::getTotalAccount();
    // ============================
    
    // create two BankAcount objects
    string name1 = "张三";
    string name2 = "李四";
    double balance1 = 1000.0;
    double balance2 = 500.0;

    BankAccount ba1(name1, balance1);
    BankAccount ba2(name2, balance2);
    BankAccount::getTotalAccount(); // should output 2 

    // deposit for ba1
    ba1.deposit(200.0);
    // withdraw from ba2 (should be 'ain't got no money')
    ba2.withdraw(600.0);

    // display bank account
    ba1.display();
    ba2.display();

    //copy ba2 to construct ba3
    BankAccount ba3(ba2);
    BankAccount::getTotalAccount(); // should output 3
    return 0;
}