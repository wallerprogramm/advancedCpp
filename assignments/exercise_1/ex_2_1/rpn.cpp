#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;


int main() {
  stack<int> mystack;
  bool quit = false;

  while(!quit) {
    string linebuffer;
    string token;
    char buffer;
    int numbuffer;
    int operand1;
    int operand2;

    // cin.get(buffer, 1);
    // getline(cin,linebuffer);
    cin >> linebuffer;
    istringstream stringstream(linebuffer);

    while (stringstream >> token) {
      if (buffer == 'n') {
        numbuffer = stoi(token);
        cout << "numbuffer is = " << numbuffer << endl;
        buffer = 'i'; //Set the buffer to something that isn't used!
      }
      else {
        buffer = token.front();
        cout << "buffer is: " << buffer << endl;
      }
      switch (buffer) {
        case 'q': return 0;
        case 'i': mystack.push(numbuffer);
                  cout << "Stack size after push: " << mystack.size() << endl;
                  break;
        case 'd': mystack.pop();
                  cout << "Stack size after pop: " << mystack.size() << endl;
                  // cout << endl;
                  break;
        case '+': if (mystack.size() >= 2) {
                    operand1 = mystack.top();
                    mystack.pop();
                    operand2 = mystack.top();
                    mystack.pop();
                    mystack.push(operand1+operand2);
                    cout << operand1 << " + " << operand2 << " = " << operand1+operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '-': if (mystack.size() >= 2) {
                    operand1 = mystack.top();
                    mystack.pop();
                    operand2 = mystack.top();
                    mystack.pop();
                    mystack.push(operand1-operand2);
                    cout << operand1 << " - " << operand2 << " = " << operand1-operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '*': if (mystack.size() >= 2) {
                    operand1 = mystack.top();
                    mystack.pop();
                    operand2 = mystack.top();
                    mystack.pop();
                    mystack.push(operand1*operand2);
                    cout << operand1 << " * " << operand2 << " = " << operand1*operand2 << endl;
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        case '/': if (mystack.size() >= 2) {
                    operand1 = mystack.top();
                    mystack.pop();
                    operand2 = mystack.top();
                    mystack.pop();
                    if (operand2 != 0) {
                      mystack.push(operand1/operand2);
                      cout << operand1 << " / " << operand2 << " = " << operand1/operand2 << endl;
                    }
                  }
                  else {
                    cout << "Not enough numbers on stack!" << endl;
                  }
                  break;
        default : cout << endl;
      }


    }





  }
}
