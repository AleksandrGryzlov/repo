#include <iostream>
using namespace std;

class Complex
{
private:
    double real = 0.0;
    double img = 0.0;
public:
    Complex() : real(0.0), img(0.0) {}
    Complex(double r, double i) : real(r), img(i) {}
    void set(double, double);
    double getReal() const;
    double getImg() const;
    Complex& Complex::addTo(Complex& rhs) {
        this->real += rhs.real;
        this->img += rhs.img;
        return *this;
    }
    Complex& Complex::multiplyBy(Complex& rhs) {
        this->real *= rhs.real;
        this->img *= rhs.img;
    }
    friend Complex operator+(const Complex& r, const Complex& i);
    friend Complex operator-(const Complex& r, const Complex& i);
    friend ofstream& operator<<(ostream& output, const Complex& input) {
        output << "Imaginary number is " << input.real << input.img;
        return output;
    }
};

Complex operator+(const Complex& r, const Complex& i) {
    return Complex{ r.real + i.img };
}

Complex operator-(const Complex& r, const Complex& i) {
    return Complex{ r.real - i.img };
}