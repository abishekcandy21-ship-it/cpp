#include <iostream>
#include <string>
using namespace std;

class TransactionHistory
{
private:
    static const int CAPACITY = 10;

    string transactions[CAPACITY];

    int count;
    int nextIndex;

public:
    TransactionHistory()
    {
        count = 0;
        nextIndex = 0;
    }

    void addTransaction(const string& transaction)
    {
        transactions[nextIndex] = transaction;

        nextIndex = (nextIndex + 1) % CAPACITY;

        if (count < CAPACITY)
            count++;
    }

    void display() const
    {
        cout << "\nLatest Transactions:\n";

        int startIndex =
            (count == CAPACITY) ? nextIndex : 0;

        for (int i = 0; i < count; i++)
        {
            int index =
                (startIndex + i) % CAPACITY;

            cout << transactions[index] << endl;
        }
    }
};

int main()
{
    TransactionHistory history;

    for (int i = 1; i <= 11; i++)
    {
        history.addTransaction(
            "Transaction " + to_string(i)
        );
    }

    history.display();

    return 0;
}