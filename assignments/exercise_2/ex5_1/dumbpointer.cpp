#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Dumb_pointer {
private:
    T *pdata;
public:
    Dumb_pointer(T* pvalue) : pdata(pvalue) {

    }

    ~Dumb_pointer() {
        delete pdata;
    }

    T& operator*() {
        return *pdata;
    }

    T* operator->() {
        return pdata;
    }

    void print() {
        cout << "Pointer address: " << pdata << endl;
        cout << "Pointer value: " << *pdata << endl;
    }
};

int main(int argc, char const *argv[]) {
    int a = 34;
    Dumb_pointer<int> pointer(&a);
    pointer.print();
    int myints[] = {1, 34 , 12, 29};
    vector<int> v(myints, myints + sizeof(myints) / sizeof(int));
    Dumb_pointer<vector<int>> vecptr(&v);
    cout << vecptr->size() << endl;
    cout << vecptr->at(2) << endl;
    return 0;
}
