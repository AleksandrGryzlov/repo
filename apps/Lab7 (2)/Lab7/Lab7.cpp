class Complex
{
private:
    double real = 0.0;
    double img = 0.0;
    Complex& addTo(Complex&);
    Complex& multiplyBy(Complex&);

public:
    Complex() : real(0.0), img(0.0) {}
    Complex(double r, double i) : real(r), img(i) {}
    void set(double, double);
    double getReal() const;
    double getImg() const;
    const Complex operator+(const Complex&);
    const Complex operator-(const Complex&);
    friend ostream& operator<<(ostream& os, const Complex& c);

    const Complex operator+(const Complex& rhs) {
        this->addTo(rhs);
        return *this;
    }
    const Complex operator-(const Complex& rhs) {
        this->multiplyBy(rhs);
        return *this;
    }
};

Complex& Complex::addTo(Complex& rhs) {
    this->real += rhs.real;
    this->img += rhs.img;
    return *this;
}

Complex& Complex::multiplyBy(Complex& rhs) {
    this->real *= rhs.real;
    this->img *= rhs.img;
}

ostream& operator<<(ostream& os, const Complex& c) 
{
    cout << c.getReal() << "+" << c.getImg() << "i";
    return os;
}

#include <iostream>
using namespace std;
int main()
{
    Complex Complex1;
    Complex1.set(1, 1);
    return 0;
}