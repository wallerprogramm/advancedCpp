#ifndef CLASS_A_H_
#define CLASS_A_H_

#include <iostream>

using namespace std;

class A {
public:
  A() {
    cout << "Constructor of class A" << endl;
  }
  ~A() {
    cout << "Destructor of class A" << endl;
  }
};

#endif // CLASS_A_H_
