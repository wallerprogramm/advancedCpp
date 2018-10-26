#include <utility>
#include <fstream>
#include <iostream>
#include <cstdio>

#include "spellchecker.h"
#include "pset.h"

using namespace std;

spellchecker::spellchecker(string dict_file, const char *text_file) : dictionary(std::move(dict_file)), text(text_file) {
    check_file();
}

spellchecker::~spellchecker() {

}

void spellchecker::check_file() {
    ifstream ifs(text);
    ofstream ofs(tmp_text);
    string current_word;
    char choice;
    char endsymbol;

    while(ifs >> current_word) {
        endsymbol = '\0';
        if (current_word.back() == '.' || current_word.back() == ',' || current_word.back() == '?' || current_word.back() == '!') {
            endsymbol = current_word.back();
            current_word.pop_back();
        }
        if (!dictionary.contains(current_word)) {
            cout << current_word << endl;
            cout << "(a)dd, (i)gnore, (r)eplace? ";
            cin >> choice;
            switch (choice) {
                case 'a': dictionary.push_back(current_word);
                    break;
                case 'i':
                    break;
                case 'r': {
                    cout << "Enter the new word: ";
                    cin >> current_word;
                }
                    break;
                default: cout << "\n(a)dd, (i)gnore, (r)eplace? ";
            }
        }
        if (endsymbol != '\0') {
            current_word.push_back(endsymbol);
        }
        ofs << current_word;
        ofs << " "; // There remains a white space at the end of the file!!
    }
    rename(tmp_text, text);
}