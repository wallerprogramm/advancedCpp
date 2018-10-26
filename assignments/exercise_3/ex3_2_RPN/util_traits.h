#include <string>
#include <sstream>
#include <complex>
#include <iostream>
#include "fraction.h"


using namespace std;


template<typename T>
struct min_traits {
    static T mymin(T a, T b) {
        return a<b ? a : b;
    }
//    static void mymin(T a, T b) {
//        cout << "Min of " << a << " and " << b;
//        cout << " is " << (a<b ? a: b) << endl;
//    }
};

template<>
struct min_traits<complex<double> > {
    static complex<double> mymin(complex<double> a, complex<double> b) {
        cout << "Be aware that for two complex numbers the min function returns the "
        << "number with the smaller norm!" << endl;
        return norm(a)<norm(b) ? a : b;
    }
//    static void mymin(complex<double> a, complex<double> b) {
//        cout << "There is no minimum of two complex numbers" << endl;
//    }
};

template<typename T>
struct extract_traits {
    static void read(string token, T numbuffer) {

  }
};

template<>
struct extract_traits<int> {
    static void read(string token, int &numbuffer) {
        numbuffer = stoi(token);
  }
};

template<>
struct extract_traits<double> {
    static void read(string token, double &numbuffer) {
        numbuffer = stod(token);
    }
};

template<>
struct extract_traits<Fraction> {
    static void read(string token, Fraction &numbuffer) {
        istringstream stringstream(token);
        Fraction f;
        stringstream >> f;
        numbuffer = f; // We could probably stringstream >> numbuffer;
  }
};
template<>
struct extract_traits<complex<double> > {
    static void read(string token, complex<double> &numbuffer) {
        istringstream stringstream(token);
        stringstream >> numbuffer;
    }
};
