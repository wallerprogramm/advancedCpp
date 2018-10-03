#include <iostream>
using namespace std;

int gcf(int a, int b) {
  return b == 0 ? a : gcf(b, a % b);
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
      return fraction(c, d);
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
    inline static void check_char(istream &is, char ch) {
      char c;
      is >> c;
      if (c != ch) {
        is.putback(c);
        is.setstate(ios::badbit);
      }
    }
    friend ostream &operator<<(ostream &os, fraction f) {
      os << '(' << f.cntr << '/' << f.denom << ')';
      return os;
    }
    friend istream &operator>>(istream &is, fraction &f) {
      fraction g;
      check_char(is, '('); is >> g.cntr;
      check_char(is, '/'); is >> g.denom;
      check_char(is, ')'); if(is) f=g;
      return is;
    }
};

void static_example() {
  fraction f1 = fraction(3, 5);
  fraction f2 = fraction(15, 7);
  cout << "Hi user, this driver tests the operators +, -, *, / with the following fractions:" << endl;
  cout << "fraction f1: " << f1 << endl;
  cout << "fraction f2: " << f2 << endl;

  cout << f1 << " + " << f2 << " = " << f1+f2 << endl;
  cout << f1 << " - " << f2 << " = " << f1-f2 << endl;
  cout << f1 << " * " << f2 << " = " << f1*f2 << endl;
  cout << f1 << " / " << f2 << " = " << f1/f2 << endl;
}

void interactive_example() {
  fraction f1;
  fraction f2;
  char operation;
  cout << "Enter your first fraction in the following way: (counter/denominator): ";
  cin >> f1;
  cout << endl;
  cout << "Enter your favourite operator form +, -, *, /: ";
  cin >> operation;
  cout << endl;
  cout << "Enter your second fraction in the following way: (counter/denominator): ";
  cin >> f2;
  cout << endl;

  switch (operation) {
    case '+': cout << f1 << " + " << f2 << " = " << f1+f2 << endl;
    break;
    case '-': cout << f1 << " - " << f2 << " = " << f1-f2 << endl;
    break;
    case '*': cout << f1 << " * " << f2 << " = " << f1*f2 << endl;
    break;
    case '/': cout << f1 << " / " << f2 << " = " << f1/f2 << endl;
    break;
    default: cout << "Unluckily, " << operation << "isn't an operator!" << endl;
  }
}

int main(int argc, char *argv[]) {
  char example_style;
  cout << "Dear user, choose either a static example by entering s or a interactive example by entering i: ";
  cin >> example_style;
  cout << endl;
  switch (example_style) {
    case 's': static_example();
    break;
    case 'i': interactive_example();
    break;
    default: cout << "Please read the instructions carfully!" << endl;
  }
}
