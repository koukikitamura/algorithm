#include <bits/stdc++.h>
using namespace std;

void error_handler() {
  cout << "error" << endl;
}

int main() {
  int num1, num2;
  string op;
  int result;
  bool is_error = false;

  cin >> num1 >> op >> num2;

  if(op == "+") {
    result = num1 + num2;
  } else if(op == "-") {
    result = num1 - num2;
  } else if(op == "*") {
    result = num1 * num2;
  } else if(op == "/") {
    if(num2 == 0) {
      error_handler();
      return 0;
    }
    result = num1 / num2;

  } else if(op == "?" || op == "=" || op == "!") {
    error_handler();
    return 0;
  }

  cout << result << endl;
}
