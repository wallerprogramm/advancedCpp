#include "fraction.h"
#include <string>
#include <sstream>

using namespace std;


template<typename T>
struct min_traits {
  static T mymin(T a, T b) {
    return a<b ? a : b;
  }
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
