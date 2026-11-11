#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    string author;
    int copies;

    static int validateCopies(int c) {
        if (c < 0)
            throw invalid_argument("Invalid number of copies");
        return c;
    }

public:
    Book() : Book("Unknown", "Unknown", 0) {}

    explicit Book(const string& t)
        : Book(t, "Unknown", 1) {}

    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(validateCopies(c)) {}

    void display() const {
        cout << title << " | " << author
             << " | " << copies << '\n';
    }
};

int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("OOP Concepts", "Balagurusamy", 5);

        b1.display();
        b2.display();
        b3.display();

        Book b4("Invalid Book", "Unknown", -3);
        b4.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}