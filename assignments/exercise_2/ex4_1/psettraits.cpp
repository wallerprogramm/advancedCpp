#include <iostream>
#include <set>
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
class pset {
    string filename;
    set <T> s;
    // std::set<T>::iterator it;

    void readvector() {
        ifstream ifs(filename);
        for (;;) {
            T x;
            persister::read(ifs, x);
//            ifs >> x;
            if (!ifs.good()) break;
            s.insert(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
//    for(const T &elem : v) ofs << elem << endl;
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

    int get_size() {
        return s.size();
    }

    // T get_vectorvalue(int i) {
    //     return v[i];
    // }
    // void print_values() {
    //   for (it=s.begin(); it!=s.end(); ++it) {
    //     cout << *it << endl;
    //   }
    // }
    set<T> get_set() {
      return s;
    }
};

// void foo(pset<int> pv) {
//     if (pv.get_size() > 0) cout << pv.get_vectorvalue(0) << endl;
//     cout << "Vector size of pv: " << pv.get_size() << endl;
//     pv.push_back(17);
//     /*The elements pushed to the vector are lost after leaving this function
//     since pv is another vector than the vector pv in main*/
// }

/*The next function fixes this problem. The parameter of food is now a pointer
to the very same vector pev we declared in the main method and by following the
pointer we write the int 17 into the original vector!*/
void food(pset<int> *pv) {
    // if (pv->get_size() > 0) cout << pv->get_vectorvalue(0) << endl;
    cout << "Set size of pev: " << pv->get_size() << endl;
    pv->push_back(17);
    for(auto elem : pv->get_set()) {
      cout << elem << endl;
    }
}

int main(int argc, char const *argv[]) {
    pset<int> pv("/tmp/pset-int.txt");
    // foo(pv);

    pset<int> pev("/tmp/pset-pev.txt");
    food(&pev);

    pset<string> pvek("/tmp/pset-pvek.txt");
    // for (size_t i = 0; i < pvek.get_size(); i++) {
    //     cout << pvek.get_vectorvalue(i) << endl;
    // }
    // pvek.print_values();
    // set<string>::iterator it;
    // set<string> = pvek.get_set();
    // for (it=s.begin(); it!=s.end(); ++it) {
    //   cout << *it << endl;
    // }
    /* use auto for automatic type deduction!!!*/
    for(auto elem : pvek.get_set()) {
      cout << elem << endl;
    }
    cout << "-------------------------" << endl;
    pvek.push_back("Neu! Hier!");
    set<string>::iterator it;
    set<string> s = pvek.get_set();
    for (it=s.begin(); it!=s.end(); ++it) {
      cout << *it << endl;
    }
    // pvek.print_values();
    // for (size_t i = 0; i < pvek.get_size(); i++) {
    //     cout << pvek.get_vectorvalue(i) << endl;
    // }
    return 0;
}
