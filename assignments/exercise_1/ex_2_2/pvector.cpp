#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template<typename T>
class pvector {
  string filename;
  vector<T> v;

  void readvector() {
    ifstream ifs(filename);
    for (;;) {
      T x;
      ifs >> x;
      if (!ifs.good()) break;
      v.push_back(x);
    }
  }

  void writevector() {
    ofstream ofs(filename);
    for(const T &elem : v) ofs << elem << endl;
  }

public:
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
void food(pvector<int>* pv) {
  if (pv->get_size() > 0) cout << pv->get_vectorvalue(0) << endl;
  cout << "Vector size of pev: " << pv->get_size() << endl;
  pv->push_back(17);
}

int main(int argc, char const *argv[]) {
  pvector<int> pv("/tmp/pvector-int.txt");
  foo(pv);

  pvector<int> pev("/tmp/pvector-pev.txt");
  food(&pev);
  return 0;
}
