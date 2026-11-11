#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

// Weight in grams
void charge(int grams)
{
    double kg = grams / 1000.0;
    double amount = kg * 50;

    cout << "Gram parcel charge: " << amount << endl;
}

// Weight in kilograms
void charge(double kg,
            bool express = false,
            bool insured = false)
{
    double amount = kg * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Kilogram parcel charge: "
         << amount << endl;
}

// Parcel object
void charge(Parcel p)
{
    double amount = p.weight * 50;

    if (p.express)
        amount += 30;

    if (p.insured)
        amount += 20;

    cout << "Parcel object charge: "
         << amount << endl;
}

int main()
{
    charge(2);
    charge(2.0);
    charge(Parcel{2.5, true, true});
    charge(2.0f);
    charge(2.0, true);
    charge(2.0, false, true);

    return 0;
}