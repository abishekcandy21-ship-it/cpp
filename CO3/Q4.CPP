#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& m) const {
        return Money(0, static_cast<int>(paise + m.paise));
    }

    Money operator-(const Money& m) const {
        return Money(0, static_cast<int>(paise - m.paise));
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;

        if (amount < 0) {
            out << "-Rs ";
            amount = -amount;
        }
        else {
            out << "Rs ";
        }

        out << amount / 100 << '.'
            << setw(2) << setfill('0') << amount % 100;

        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        in >> rupees >> p;

        if (in)
            m.paise = rupees * 100 + p;

        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);

    Money c = a + b;

    cout << c << '\n';
    cout << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << x + y << '\n';

    Money z = Money(10) - Money(15);
    cout << z << '\n';

    a += b;
    cout << a << '\n';

    return 0;
}