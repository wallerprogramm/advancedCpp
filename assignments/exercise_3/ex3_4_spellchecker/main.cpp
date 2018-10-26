#include <iostream>
#include <string>
#include "pset.h"
#include "spellchecker.h"


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
    spellchecker checker(argv[1], argv[2]);
    return 0;
}
