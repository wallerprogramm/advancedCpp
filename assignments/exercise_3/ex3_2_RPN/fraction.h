#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Fraction {
    int cntr;
    int denom;

public:
    Fraction(int c=0, int d=1);

    int get_counter(void);

    void set_cntr(int c);

    int get_denominator(void);

    Fraction operator+(Fraction b);

    Fraction operator-(Fraction b);

    Fraction operator*(Fraction b);

    Fraction operator/(Fraction b);

    bool operator<(Fraction b);

    // inline static void check_char(istream &is, char ch) {
    //     char c;
    //     is >> c;
    //     if (c != ch) {
    //         is.putback(c);
    //         is.setstate(ios::badbit);
    //     }
    // }
    friend ostream &operator<<(ostream &os, Fraction f);

    friend istream &operator>>(istream &is, Fraction &f);

    friend istringstream &operator>>(istringstream &is, Fraction &f);
};

#endif // FRACTION_H_
