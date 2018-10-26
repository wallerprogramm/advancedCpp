#ifndef PVECTOR_H_
#define PVECTOR_H_

#include <vector>
#include <fstream>
#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pvector {
    string filename;
    vector <T> v;

    void readvector() {
        ifstream ifs(filename);
        for (;;) {
            T x;
            persister::read(ifs, x);
            if (!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
        for (const T &elem : v) persister::write(ofs, elem);
    }

public:
    typedef P persister;

    pvector(string fname) : filename(fname) {
        readvector();
    }

    ~pvector() {
        writevector();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    int size() {
        return v.size();
    }

    T get_vectorvalue(int i) {
        return v[i];
    }

    T back() {
      return v.back();
    }
};

#endif // PVECTOR_H_
