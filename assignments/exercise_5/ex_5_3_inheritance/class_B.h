#ifndef CLASS_B_H_
#define CLASS_B_H_

#include "class_A.h"


class B : public A {
public:
  B() {
    cout << "Constructor of class B" << endl;
  }
  ~B() {
    cout << "Destructor of class B" << endl;
  }
};

#endif // CLASS_B_H_
