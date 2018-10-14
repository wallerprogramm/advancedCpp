#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void c_swap(int *x, int *y) {
  int z = *x;
  *x = *y;
  *y = z;
}

int main(int argc, char const *argv[]) {
  int a = 3;
  int b = 5;
  int x = 3;
  int y = 5;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "-------------------------";
  swap(a, b);
  c_swap(&x, &y);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  /* code */
  return 0;
}
