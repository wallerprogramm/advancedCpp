#include "fraction.h"
#include "rpn_calculator.h"
#include <iostream>
#include <string>

using namespace std;

inline void helper() {
  cout << endl
		<< "Use the following commands:" << endl << endl
		<< "  n [number]  --  push [number] on stack" << endl
		<< "  +           --  add the first two [number]s on stack" << endl
		<< "  -           --  subtract the second from the first [number] on stack" << endl
		<< "  *           --  multiply first two [number]s on stack" << endl
		<< "  /           --  divide the first [number] by the second on stack" << endl
		<< "  min         --  get the minimum of the first two [number]s on stack" << endl
		<< "  d           --  delete first [number] on stack" << endl
		<< "  q           --  quit" << endl << endl
		<< "Fractions can be entered as: (cntr/denom)" << endl << endl;
// << "Example usage: n 3 n 2 n 1 + * n 3 /" << endl << endl;
}

int main(int argc, char const *argv[]) {
  string datatype;
  cout << "Welcome to the rpn calculator. Enter int, double or fraction." << endl;
  cin >> datatype;
  if (datatype == "int") {
    RPN<int> rpn("/tmp/pvectorstack_int.txt");
    helper();
    rpn.run_rpn();
  }
  else if (datatype == "double") {
    RPN<double> rpn("/tmp/pvectorstack_double.txt");
    helper();
    rpn.run_rpn();
  }
  else if (datatype == "fraction") {
    RPN<Fraction> rpn("/tmp/pvectorstack_Fraction.txt");
    helper();
    rpn.run_rpn();
  }
  else {
    cout << endl;
    cout << "Please choose a correct type" << endl;
  }
  return 0;
}
