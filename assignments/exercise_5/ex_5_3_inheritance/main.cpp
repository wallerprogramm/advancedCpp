#include "class_C.h"

void create_c() {
  C c;
}

int main(int argc, char const *argv[]) {
  create_c();
  return 0;
}

/*As the output of this program shows:
  Constructor of class A
  Constructor of class B
  Constructor of class C
  Destructor of class C
  Destructor of class B
  Destructor of class A*/
