#ifndef FIBONACCI_H_
#define FIBONACCI_H_

namespace simple_fib_ {
  template<int T>
  struct Fibonacci {
    static const int res = Fibonacci<T - 1>::res + Fibonacci<T - 2>::res;
  };

  template<>
  struct Fibonacci<2> {
    static const int res = 1;
  };

  template<>
  struct Fibonacci<1> {
    static const int res = 1;
  };

  template<>
  struct Fibonacci<0> {
    static const int res = 0;
  };
}

namespace constexpr_fib_ {
  constexpr int fibonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

#endif // FIBONACCI_H_
