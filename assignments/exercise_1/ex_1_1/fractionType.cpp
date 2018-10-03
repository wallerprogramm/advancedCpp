#include <iostream>
using namespace std;

int gcf(int a, int b) {
  return b == 0 ? a : gcf(b, a % b)
}

int lcm(int a, int b) {
  return (a * b) / gcf(a, b);
}

class fraction {
  int cntr;
  int denom;

public:
  fraction(int c=0, int d=1) :
    cntr(c), denom(d)
    { /*void*/}
    int get_counter(void) {
      return cntr;
    }
    void set_cntr(int c) {
      cntr = c;
    }
    int get_denominator(void) {
      return denom;
    }
    fraction operator+(fraction b) {
      int d = lcm(denom, b.get_denominator());
      int c = (cntr*d/denom) + (b.get_counter()*d/b.get_denominator());
      return fraction(c, d);
    }
    fraction operator-(fraction b) {
      int d = lcm(denom, b.get_denominator());
      int c = (cntr*d/denom) - (b.get_counter()*d/b.get_denominator());
      return fraction(c, d)
    }
    fraction operator*(fraction b) {
      int f1 = gcf(cntr, b.denom); //b.cntr ---> we can access privates of same type
      int f2 = gcf(b.cntr, denom);
      return fraction((cntr/f1) * (b.cntr/f2), (denom/f2) * (b.denom/f1));
    }
    fraction operator/(fraction b) {
      fraction invers_b = fraction(b.get_denominator(), b.get_counter());
      return (*this) * invers_b;
    }
    inline void check_char(iostream &is, char ch) {
      char c;
      is >> c;
      if (c != ch) {
        is.putback(c);
        is.setstate(ios::badbit);
      }
    }
    ostream &operator<<(ostream &os, fraction f) {
      os << '(' << f.cntr << '/' << f.denom << ')';
      return os;
    }
    istream &operator>>(istream &is, fraction &f) {
      fraction g;
      check_char('('); is >> g.cntr;
      check_char('/'); is >> g.denom;
      check_char(')'); if(is) f=g;
      return is;
    }
}

void main(int argc, char *argv[]) {
  fraction f(atoi(argv[1]), atoi(argv[2]));
  cout << f.get_counter() << ":" << f.get_denominator() << endl '\n';
}
