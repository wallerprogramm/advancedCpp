#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main() {
  vector<int> vectorstack;
  bool quit = false;

  while(!quit) {
    string linebuffer;
    string token;
    char buffer;
    int numbuffer;
    int operand1;
    int operand2;

    std::getline(cin, linebuffer);
    istringstream stringstream(linebuffer);

    while (stringstream >> token) {
      if (buffer == 'n') {
        numbuffer = stoi(token);
        buffer = 'i'; //Set the buffer to something that isn't used!
      }
      else {
        buffer = token.front();
      }
      switch (buffer) {
        case 'q': return 0;
        case 'i': vectorstack.push_back(numbuffer);
                  break;
        case 'd': vectorstack.pop_back();
                  break;
        case '+': if (vectorstack.size() >= 2) {
                    operand1 = vectorstack.back();
                    vectorstack.pop_back();
                    operand2 = vectorstack.back();
                    vectorstack.pop_back();
                    vectorstack.push_back(operand1+operand2);
                    cout << operand1 << " + " << operand2 << " = " << operand1+operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '-': if (vectorstack.size() >= 2) {
                    operand1 = vectorstack.back();
                    vectorstack.pop_back();
                    operand2 = vectorstack.back();
                    vectorstack.pop_back();
                    vectorstack.push_back(operand1-operand2);
                    cout << operand1 << " - " << operand2 << " = " << operand1-operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '*': if (vectorstack.size() >= 2) {
                    operand1 = vectorstack.back();
                    vectorstack.pop_back();
                    operand2 = vectorstack.back();
                    vectorstack.pop_back();
                    vectorstack.push_back(operand1*operand2);
                    cout << operand1 << " * " << operand2 << " = " << operand1*operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '/': if (vectorstack.size() >= 2) {
                    operand1 = vectorstack.back();
                    vectorstack.pop_back();
                    operand2 = vectorstack.back();
                    vectorstack.pop_back();
                    if (operand2 != 0) {
                      vectorstack.push_back(operand1/operand2);
                      cout << operand1 << " / " << operand2 << " = " << operand1/operand2 << endl;
                    }
                    else {
                      cout << "Division by zero is not allowed!" << endl;
                    }
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        default : break;
      }
    }
    if (stringstream.gcount() == 0) {
      for (size_t i = 0; i < vectorstack.size(); i++) {
        cout << i+1 << ": " << vectorstack[i] << endl;
      }
    }
  }
  return 0;
}
