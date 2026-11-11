#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw domain_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const {
        const double EPS = 1e-9;

        return fabs(real - c.real) < EPS &&
               fabs(imag - c.imag) < EPS;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        Complex R(10, 0);
        Complex L(0, 5);
        Complex C(0, -2);

        Complex series = R + L + C;

        cout << "Series impedance: " << series << '\n';
        cout << "Series magnitude: "
             << series.magnitude() << '\n';

        Complex parallel = (R * L) / (R + L);

        cout << "Parallel impedance: " << parallel << '\n';
        cout << "Parallel magnitude: "
             << parallel.magnitude() << '\n';

        Complex zero(0, 0);
        Complex result = R / zero;

        cout << result << '\n';
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}