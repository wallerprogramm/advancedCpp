#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Foo {
    int u;

public:
    Foo(int num) : u(num) {}

    void print() {
        cout << "Another foo with number " << u << endl;
    }
};

int main(int argc, char** argv) {
    vector<Foo*> foos;
    Foo f1(1), f2(2), f3(1000), f4(234);
    foos.push_back(&f1);
    foos.push_back(&f2);
    foos.push_back(&f3);
    foos.push_back(&f4);

    for_each(foos.begin(), foos.end(), mem_fun(&Foo::print));

    return 0;
}
