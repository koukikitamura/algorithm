#include<iostream>
using namespace std;

const string end_of_text = "END_OF_TEXT";

string to_lower(string word) {
  string lower = "";

  for(int i = 0; i < word.size(); i++) {
    lower += tolower(word[i]);
  }

  return lower;
}


int main() {
  string target;
  int count = 0;

  cin >> target;
  target = to_lower(target);

  while(true) {
    string word;
    cin >> word;

    if(to_lower(word)== target) {
      count++;
    }

    if(word == end_of_text) {
      break;
    }
  }

  printf("%d\n", count);
}
