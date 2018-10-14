#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


template<typename T>
struct persistence_traits {
    static void read(ifstream &i, T &elem) {

    }

    static void write(ofstream &o, const T &elem) {

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

template<>
struct persistence_traits<int> {
    static void read(ifstream &ifs, int &elem) {
        ifs >> elem;
    }

    static void write(ofstream &ofs, const int &elem) {
        ofs << elem << endl;
    }
};

template<typename T, typename P=persistence_traits<T>>
class pvector {
    string filename;
    vector <T> v;

    void readvector() {
        ifstream ifs(filename);
        for (;;) {
            T x;
            persister::read(ifs, x);
//            ifs >> x;
            if (!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
//    for(const T &elem : v) ofs << elem << endl;
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

    int get_size() {
        return v.size();
    }

    T get_vectorvalue(int i) {
        return v[i];
    }
};

void foo(pvector<int> pv) {
    if (pv.get_size() > 0) cout << pv.get_vectorvalue(0) << endl;
    cout << "Vector size of pv: " << pv.get_size() << endl;
    pv.push_back(17);
    /*The elements pushed to the vector are lost after leaving this function
    since pv is another vector than the vector pv in main*/
}

/*The next function fixes this problem. The parameter of food is now a pointer
to the very same vector pev we declared in the main method and by following the
pointer we write the int 17 into the original vector!*/
void food(pvector<int> *pv) {
    if (pv->get_size() > 0) cout << pv->get_vectorvalue(0) << endl;
    cout << "Vector size of pev: " << pv->get_size() << endl;
    pv->push_back(17);
}

int main(int argc, char const *argv[]) {
    pvector<int> pv("/tmp/pvector-int.txt");
    foo(pv);

    pvector<int> pev("/tmp/pvector-pev.txt");
    food(&pev);

    pvector<string> pvek("/tmp/pvector-pvek.txt");
    for (size_t i = 0; i < pvek.get_size(); i++) {
        cout << pvek.get_vectorvalue(i) << endl;
    }
    cout << "-------------------------" << endl;
    pvek.push_back("Neu! Hier!");
    for (size_t i = 0; i < pvek.get_size(); i++) {
        cout << pvek.get_vectorvalue(i) << endl;
    }
    return 0;
}
