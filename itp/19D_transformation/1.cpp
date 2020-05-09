#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main() {
  string target;
  int commnad_num;

  cin >> target;
  cin >> commnad_num;

  for(int i = 0; i < commnad_num; i++) {
    string command;
    int top_index, tail_index;
    cin >> command >> top_index >> tail_index;

    if(command == "print") {
      string sub_str = target.substr(top_index, tail_index - top_index + 1);
      cout << sub_str << endl;
    } else if(command == "reverse") {
      string sub_str = target.substr(top_index, tail_index - top_index + 1);
      reverse(sub_str.begin(), sub_str.end());
      target.replace(top_index, sub_str.size(), sub_str);
    } else if(command == "replace") {
      string sub_str;
      cin >> sub_str;

      target.replace(top_index, sub_str.size(), sub_str);
    }
  }
}
