#include <iostream>
#include <map>

using namespace std;

void print(map<string, string> m) {
    for(auto it=m.begin(); it != m.end(); ++it) {
        cout << "phone number: " << it->first << " name: " << it->second << endl;
    }
    cout << endl;
}

int main(int argc, char** argv) {
    map<string, string> phone1;
    map<string, string> phone2;

    phone1.insert(pair<string, string>("+41 79 345 12 21", "Peter"));
    phone1.insert(pair<string, string>("+41 79 666 66 66", "Robert"));
    phone1.insert(pair<string, string>("+41 77 121 11 22", "Peter"));
    phone1.insert(pair<string, string>("+41 78 735 15 98", "Jane"));


    phone2.insert(pair<string, string>("+41 79 345 12 21", "Peter"));
    phone2.insert(pair<string, string>("+41 76 845 23 67", "Lisa"));
    phone2.insert(pair<string, string>("+41 77 999 99 99", "Hannah"));

    cout << "phone1: " << endl;
    print(phone1);
    cout << "phone2: " << endl;
    print(phone2);

    map<string, string> new_phone = phone1;

    // now merge the two contact maps
    new_phone.insert(phone2.begin(), phone2.end());
    cout << "merged contacts:" << endl;
    print(new_phone);

    return 0;
}
