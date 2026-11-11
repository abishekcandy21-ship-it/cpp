#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << endl;
}

void applyByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent)
{
    if (fee != nullptr)
    {
        *fee -= (*fee) * percent / 100;
    }
}

int main()
{
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    applyByValue(fee1, 10);
    cout << "Stored fee after value: " << fee1 << endl;

    applyByReference(fee2, 10);
    cout << "Stored fee after reference: " << fee2 << endl;

    applyByPointer(&fee3, 10);
    cout << "Stored fee after pointer: " << fee3 << endl;

    return 0;
}
