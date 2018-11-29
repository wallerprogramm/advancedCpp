#include <iostream>

#include "bin_op.h"

struct double_it : public std::unary_function<int, int> {
    int operator() (int i) const { return 2 * i; }
};

struct tripple_it : public std::unary_function<int, int> {
    int operator() (int i) const { return 3 * i; }
};

struct add : public std::binary_function<int, int, int> {
    int operator() (int a, int b) { return a + b; }
};

int main(int argc, char const *argv[]) {


    auto op = somefunction_t<add, double_it, tripple_it>(add(), double_it(), tripple_it());

    std::cout << op(5) << '\n';
    std::cout << op(2) << '\n';

  return 0;
}
