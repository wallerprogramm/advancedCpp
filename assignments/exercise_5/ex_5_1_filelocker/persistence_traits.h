#ifndef PERSISTENCE_TRAITS_H_
#define PERSISTENCE_TRAITS_H_

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
struct persistence_traits {
    static void read(ifstream &ifs, T &elem) {
        ifs >> elem;
    }

    static void write(ofstream &ofs, const T &elem) {
        ofs << elem << endl;
    }
};

template<>
struct persistence_traits<string> {
    static void read(ifstream &ifs, string &elem) {
        getline(ifs, elem);
    }

    static void write(ofstream &ofs, const string &elem) {
        ofs << elem << endl;
    }
};

#endif // PERSISTENCE_TRAITS_H_
