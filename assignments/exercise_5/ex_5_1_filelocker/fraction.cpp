#include "fraction.h"
#include <iostream>

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcf(a, b);
}

Fraction::Fraction(int c, int d) : cntr(c), denom(d) {
    /*void*/
}

int Fraction::get_counter(void) {
    return cntr;
}

void Fraction::set_cntr(int c) {
    cntr = c;
}

int Fraction::get_denominator(void) {
    return denom;
}

Fraction Fraction::operator+(Fraction b) {
    int d = lcm(denom, b.get_denominator());
    int c = (cntr*d/denom) + (b.get_counter()*d/b.get_denominator());
    return Fraction(c, d);
}

Fraction Fraction::operator-(Fraction b) {
    int d = lcm(denom, b.get_denominator());
    int c = (cntr*d/denom) - (b.get_counter()*d/b.get_denominator());
    return Fraction(c, d);
}

Fraction Fraction::operator*(Fraction b) {
    int f1 = gcf(cntr, b.denom); //b.cntr ---> we can access privates of same type
    int f2 = gcf(b.cntr, denom);
    return Fraction((cntr/f1) * (b.cntr/f2), (denom/f2) * (b.denom/f1));
}

Fraction Fraction::operator/(Fraction b) {
    Fraction invers_b = Fraction(b.get_denominator(), b.get_counter());
    return (*this) * invers_b;
}

bool Fraction::operator<(Fraction b) {
    int d = lcm(denom, b.get_denominator());
    int cntr_a = cntr*d/denom;
    int cntr_b = b.get_counter()*d/b.get_denominator();
    if (cntr_a < cntr_b) {
        return true;
    }
    else {
        return false;
    }
}

inline static void check_char(istream &is, char ch) {
   char c;
   is >> c;
   if (c != ch) {
       is.putback(c);
       is.setstate(ios::badbit);
   }
}

ostream &operator<<(ostream &os, Fraction f) {
    os << '(' << f.cntr << '/' << f.denom << ')';
    return os;
}
istream &operator>>(istream &is, Fraction &f) {
    Fraction g;
    check_char(is, '('); is >> g.cntr;
    check_char(is, '/'); is >> g.denom;
    check_char(is, ')'); if(is) f=g;
    return is;
}
istringstream &operator>>(istringstream &is, Fraction &f) {
    Fraction g;
    check_char(is, '(');
    is >> g.cntr;
    check_char(is, '/');
    is >> g.denom;
    check_char(is, ')');
    if (is) f = g;
    return is;
}
