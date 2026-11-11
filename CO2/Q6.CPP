#include <iostream>
#include <cstdlib>
using namespace std;

class Time
{
private:
    int h, m;

public:
    Time(int hh, int mm)
        : h(hh), m(mm)
    {
    }

    friend int minutesBetween(
        const Time& a,
        const Time& b
    );

    friend bool earlier(
        const Time& a,
        const Time& b
    );
};

inline int minutesBetween(
    const Time& a,
    const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return abs(first - second);
}

inline bool earlier(
    const Time& a,
    const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return first < second;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival)
         << " "
         << boolalpha
         << earlier(arrival, departure)
         << endl;

    Time t1(11, 30);
    Time t2(12, 15);

    cout << "Difference: "
         << minutesBetween(t1, t2)
         << " minutes" << endl;

    cout << "Is first time earlier? "
         << earlier(t1, t2) << endl;

    return 0;
}