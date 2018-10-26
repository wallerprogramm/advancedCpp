#ifndef PSET_H_
#define PSET_H_

#include <set>
#include <fstream>
#include "persistence_traits.h"


using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset {
    string filename;
    set <T> s;

    void readvector() {
        ifstream ifs(filename);
        for (;;) {
            T x;
            persister::read(ifs, x);
            if (!ifs.good()) break;
            s.insert(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
        for (const T &elem : s) persister::write(ofs, elem);
    }

public:
    typedef P persister;

    pset(string fname) : filename(fname) {
        readvector();
    }

    ~pset() {
        writevector();
    }

    void push_back(const T &el) {
        s.insert(el);
    }

    void pop_back() {
        s.erase(s.last());
    }

    int size() {
        return s.size();
    }

    // T get_vectorvalue(int i) {
    //     return v[i];
    // }

    set<T> get_set() {
      return s;
    }

    bool contains(string word) {
        return (s.find(word) != s.end());
    }
};

#endif // PSET_H_
