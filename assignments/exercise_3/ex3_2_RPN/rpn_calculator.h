#ifndef RPN_CALCULATOR_H_
#define RPN_CALCULATOR_H_

#include <iostream>
#include <sstream>
#include "pvector.h"
#include "util_traits.h"


// template<typename T, typename E=extract_traits<T>, typename M=min_traits<T>, typename P=pvector<T>>
// class RPN {
//     P vectorstack;
//     bool quit = false;
//
// public:
//     typedef E extractor;
//     typedef M minimizer;
//
//     RPN(string filename);
//
//     ~RPN();
//
//     int run_rpn();
// };

template<typename T, typename E=extract_traits<T>, typename M=min_traits<T>, typename P=pvector<T>> // Maybe we need here a trait
class RPN {
  P vectorstack;
  bool quit = false;

public:
  typedef E extractor;
  typedef M minimizer;

  RPN(string filename) : vectorstack(filename) {

  }

  ~RPN() {

  }

  int run_rpn() {
    while(!quit) {
      string linebuffer;
      string token;
      char buffer;
      T numbuffer;
      T operand1;
      T operand2;
      T minimum;

      std::getline(cin, linebuffer);
      istringstream stringstream(linebuffer);

      while (stringstream >> token) {
        if (buffer == 'n') {
          extractor::read(token, numbuffer);
          buffer = 'z'; //Set the buffer to something that isn't used!
        }
        else if (token == "min") {
            buffer = 'm';
        }
        else {
          buffer = token.front();
        }
        switch (buffer) {
          case 'q': return 0;
          case 'z': vectorstack.push_back(numbuffer);
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
                      if (true) {//(operand2 != 0) {
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
          case 'm': if (vectorstack.size() >= 2) {
                      operand1 = vectorstack.back();
                      vectorstack.pop_back();
                      operand2 = vectorstack.back();
                      vectorstack.pop_back();
                      minimum = minimizer::mymin(operand1, operand2);
                      vectorstack.push_back(minimum);
//                      minimizer::mymin(operand1, operand2);
                      cout << "Min of " << operand1 << " and " << operand2;
                      cout << " is " << minimum << endl;
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
          cout << i+1 << ": " << vectorstack.get_vectorvalue(i) << endl;
        }
      }
    }
    return 0;
  }
};

#endif // RPN_CALCULATOR_H_
