#include <iostream>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;

    string transactions[10];
    int count;
    int nextIndex;

    void addTransaction(const string& transaction)
    {
        transactions[nextIndex] = transaction;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
            count++;
    }

public:
    SavingsAccount(int acc, double initialBalance)
        : accountNumber(acc),
          balance(initialBalance),
          count(0),
          nextIndex(0)
    {
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;

            addTransaction(
                "Deposit: +" + to_string(amount)
            );
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;

            addTransaction(
                "Withdrawal: -" + to_string(amount)
            );
        }
        else
        {
            cout << "Invalid withdrawal" << endl;
        }
    }

    void miniStatement() const;
    
    double getBalance() const
    {
        return balance;
    }
};

void SavingsAccount::miniStatement() const
{
    cout << "\nAccount Number: "
         << accountNumber << endl;

    cout << "Mini Statement:\n";

    int start = (count == 10) ? nextIndex : 0;

    for (int i = 0; i < count; i++)
    {
        int index = (start + i) % 10;

        cout << transactions[index] << endl;
    }

    cout << "Current Balance: "
         << balance << endl;
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}