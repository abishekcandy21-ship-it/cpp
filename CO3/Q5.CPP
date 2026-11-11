#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        seconds = h * 3600 + m * 60 + s;
    }

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << h << ":"
             << (m < 10 ? "0" : "") << m << ":"
             << (s < 10 ? "0" : "") << s << '\n';
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(const vector<string>& t) : tracks(t) {}

    string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");

        return tracks[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");

        return tracks[index];
    }
};

int main() {
    Time t(0, 0, 5);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "Current time = ";
    t.display();

    Playlist p({"Song One", "Song Two", "Song Three"});

    cout << p[0] << '\n';
    cout << p[1] << '\n';

    try {
        cout << p[3] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }

    return 0;
}