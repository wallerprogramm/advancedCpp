#include <iostream>
#include "gcd.h"
#include "fibonacci.h"

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "gcd with simple meta-programming:\n" << endl;
  cout << "gcd(9, 15) = " << simple_gcd_::gcd<9, 15>::res << endl;
  cout << "gcd(12, 48) = " << simple_gcd_::gcd<12, 48>::res << endl;
  // Both prime
  cout << "gcd(1459, 37811) = " << simple_gcd_::gcd<1459, 37811>::res << '\n' << endl;

  cout << "gcd with constexpr:\n" << endl;
  constexpr int res_9 = constexpr_gcd_::gcd(9, 15);
  constexpr int res_12 = constexpr_gcd_::gcd(12, 48);
  // Both prime
  constexpr int res_1459 = constexpr_gcd_::gcd(1459, 37811);
  cout << "gcd(9, 15) = " << res_9 << endl;
  cout << "gcd(12, 48) = " << res_12 << endl;
  cout << "gcd(1459, 37811) = " << res_1459 << '\n' << endl;

  cout << "Fibonacci with simple meta-programming:\n" << endl;

  cout << "fibonacci(5) = " << simple_fib_::Fibonacci<5>::res << endl;
  cout << "fibonacci(10) = " << simple_fib_::Fibonacci<10>::res << endl;
  cout << "fibonacci(20) = " << simple_fib_::Fibonacci<20>::res << '\n' << endl;

  cout << "Fibonacci with constexpr:\n" << endl;

  constexpr int res_5 = constexpr_fib_::fibonacci(5);
  constexpr int res_10 = constexpr_fib_::fibonacci(10);
  constexpr int res_20 = constexpr_fib_::fibonacci(20);
  cout << "fibonacci(5) = " << res_5 << endl;
  cout << "fibonacci(10) = " << res_10 << endl;
  cout << "fibonacci(20) = " << res_20 << endl;


  return 0;
}
