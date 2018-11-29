#ifndef GCD_H_
#define GCD_H_

namespace simple_gcd_ {
  template<int A, int B>
  struct gcd {
    static const int res = gcd<B, A % B>::res;
  };

  template<int A>
  struct gcd<A, 0>{
    static const int res = A;
  };
}

namespace constexpr_gcd_ {
  constexpr int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }
}


#endif // GCD_H_
