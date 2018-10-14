#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {

    }

    ~Student() {}

    string method1() {
        return "Method1";
    }

    string method2() {
        return "Method2";
    }

    string method3() {
        return "Method3";
    }

    string get_name() {
        return name;
    }

    friend ostream &operator<<(ostream &os, Student s) {
        os << s.name;
        return os;
    }
};

class Object {
public:
    void method1() {}
    void method2() {}
    void method3() {}
};

class Rcounter {
private:
    int count;

public:
    void add_ref() {
        count++;
    }

    int remove_ref() {
        return --count;
    }

    int get_counter() {
        return count;
    }
};

template<typename T>
class smart_pointer {
private:
    T* pdata;
    Rcounter* reference;
public:
    smart_pointer(T* pvalue) : pdata(pvalue) {
        reference = new Rcounter();
        reference->add_ref();
    }

    smart_pointer(const smart_pointer<T>& sp) : pdata(sp.pdata), reference(sp.reference) {
        reference->add_ref();
    }

    ~smart_pointer() {
        if(reference->remove_ref() == 0) {
            delete pdata;
            delete reference;
        }
    }

    T& operator*() {
        return *pdata;
    }

    T* operator->() {
        return pdata;
    }

    smart_pointer<T>& operator=(const smart_pointer<T>& sp) {
        if(this != &sp) {
            if(reference->remove_ref() == 0) {
                delete pdata;
                delete reference;
            }
            pdata = sp.pdata;
            reference = sp.reference;
            reference->add_ref();
        }
        return *this;
    }

    void print() {
        cout << "Pointer address: " << pdata << endl;
        cout << "Pointer value: " << *pdata << endl;
    }

    int counter() {
        return reference->get_counter();
    }
};


void print(smart_pointer<Student> p) {
    Student s = *p;
//    cout << p.counter() << ": " << s.get_name() << endl;
    cout << p.counter() << ": " << *p << endl;
}

void foo() {
    Student *o1 = new Student("Peter", 22);         // let's create our 1st object
    Student *o2 = new Student("James", 44);         // let's create our 2nd object
//    Object *o1 = new Object();         // let's create our 1st object
//    Object *o2 = new Object();         // let's create our 2nd object
    smart_pointer<Student> p(o1);      // ref counter is 1 for 1st object
    cout << p.counter() << endl;      // displays 1
    smart_pointer<Student> q(p);
// another smart pointer that points to o1 (overload copy constructor)
    cout << p.counter() << endl;      // displays 2 (two smart pointers refer to o1)
    cout << q.counter() << endl;      // displays 2 (two smart pointers refer to o1)
    smart_pointer<Student> r(o2);      // ref counter is 1 for 2nd object
    cout << r.counter() << endl;      // displays 1
    q = r;                              // decrease counter for 1st object and
// increase counter for 2nd object (overload assignment operator)
    cout << p.counter() << endl;      // displays 1
    cout << q.counter() << endl;      // displays 2
    cout << r.counter() << endl;      // displays 2
    print(p);                         // displays 2, and the 1st object, don't delete the object pointed to by p
    print(q);                         // displays 3, and the 2nd object, don't delete the object pointed to by q
    print(r);                         // displays 3, and the 2nd object, don't delete the object pointed to by r
    cout << *p << *r << endl;         // display 1st and 2nd object (overload operator*)
    cout << p->method1() << q->method2() << r->method3() << endl;
// invoke method1 on 1st object and
// invoke method2 on 2nd object and
// invoke method3 on 2nd object (overload operator->)
}
// now the destructors of p, q, and r are called, make sure that 1st
// and 2nd object is each deleted once (i.e., when the counter reaches 0)



int main(int argc, char const *argv[]) {
    foo();

    return 0;
}