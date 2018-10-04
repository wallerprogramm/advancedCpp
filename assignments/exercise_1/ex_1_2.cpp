#include <iostream>
using namespace std;

// It appears that this is inlined.
inline static int power_of_2(int power) {
  if (power > 1) {
    return 2*power_of_2(--power);
  }
  else {
    return 2;
  }
}

int main() {
  int result = power_of_2(8);
  cout << "2^8 = " << result << endl;
  return 0;
}
