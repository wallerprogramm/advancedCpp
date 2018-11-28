#ifndef CLASS_C_H_
#define CLASS_C_H_

#include "class_B.h"


class C : public B {
public:
  C() {
    cout << "Constructor of class C" << endl;
  }
  ~C() {
    cout << "Destructor of class C" << endl;
  }
};

#endif // CLASS_C_H_
