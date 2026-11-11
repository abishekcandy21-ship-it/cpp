#include <iostream>
#include <stdexcept>
using namespace std;

class Event {
    int rows;
    int seats;
    bool** seatMap;
    int booked;

public:
    Event(int r, int s)
        : rows(r), seats(s), seatMap(nullptr), booked(0) {

        if (rows < 0 || seats < 0)
            throw invalid_argument("Invalid dimensions");

        if (rows == 0) {
            cout << "Event created with zero rows\n";
            return;
        }

        seatMap = new bool*[rows]{};

        try {
            for (int i = 0; i < rows; i++)
                seatMap[i] = new bool[seats]{};
        }
        catch (...) {
            for (int i = 0; i < rows; i++)
                delete[] seatMap[i];

            delete[] seatMap;
            seatMap = nullptr;
            throw;
        }

        cout << "Event created\n";
    }

    void bookSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat\n";
            return;
        }

        if (!seatMap[r][s]) {
            seatMap[r][s] = true;
            booked++;
            cout << "Seat booked\n";
        }
        else {
            cout << "Seat already booked\n";
        }
    }

    void cancelSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat\n";
            return;
        }

        if (seatMap[r][s]) {
            seatMap[r][s] = false;
            booked--;
            cout << "Seat cancelled\n";
        }
    }

    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;

    ~Event() {
        for (int i = 0; i < rows; i++)
            delete[] seatMap[i];

        delete[] seatMap;

        cout << "Event closed. Booked seats: "
             << booked << '\n';
    }
};

int main() {
    Event e1(2, 3);
    e1.bookSeat(0, 1);
    e1.bookSeat(1, 2);
    e1.cancelSeat(0, 1);

    {
        Event e2(3, 4);
        e2.bookSeat(1, 1);
    }

    Event* e3 = new Event(2, 2);
    e3->bookSeat(0, 0);
    delete e3;

    Event e4(0, 5);

    return 0;
}