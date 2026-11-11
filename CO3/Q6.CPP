#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    Text(const Text& t) {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }

        return *this;
    }

    Text operator+(const Text& t) const {
        size_t len1 = strlen(data);
        size_t len2 = strlen(t.data);

        char* temp = new char[len1 + len2 + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);

        delete[] temp;
        return result;
    }

    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    bool operator!=(const Text& t) const {
        return !(*this == t);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;

    cout << "Combined text: " << result << '\n';

    Text x("Hello");
    Text y("Hello");

    cout << boolalpha;
    cout << "Equal: " << (x == y) << '\n';
    cout << "Not equal: " << (x != y) << '\n';

    Text empty("");
    cout << "Empty text: [" << empty << "]\n";

    x = x;

    cout << "After self-assignment: " << x << '\n';

    return 0;
}