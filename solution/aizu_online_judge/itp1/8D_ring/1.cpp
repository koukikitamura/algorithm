#include <iostream>
#include <string>

using namespace std;

int main() {
  string target;
  string pattern;
  string double_target;

  cin >> target >> pattern;

  double_target = target + target.substr(0, target.size() - 1);

  if(double_target.find(pattern) != string::npos) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
