#ifndef SPELLCHECKER_H_
#define SPELLCHECKER_H_

//#include <set>
//#include <fstream>
#include <string>
#include "pset.h"


using namespace std;

class spellchecker {
    pset<string> dictionary;
    const char *text;
    const char *tmp_text = "tmp.txt";

public:
    spellchecker(string dict_file, const char *text_file);
    ~spellchecker();

    void check_file();
};

#endif // SPELLCHECKER_H_