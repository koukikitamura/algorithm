#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#define COMMAND_MAX_SIZE 7 + 1
#define WORD_MAX_SIZE 12 + 1
using namespace std;
using Dictionary = map<string, bool>;

// mapは2分探索なので高速ではあるが文字列の種類が少ないことから、
// 違う解答を想定している可能性が高い。

// 関数呼び出しを使うのをやめたら、Time Limit Exceeded で落ちていたものが通った。

int main() {
  int command_num;
  Dictionary dictionary;
  scanf("%d", &command_num);

  for(int i = 0; i < command_num; i++) {
    char command[COMMAND_MAX_SIZE];
    scanf("%s", command);

    if(command[0] == 'i') {
      string word;
      cin >> word;

      dictionary[string(word)] = true;
    } else if(command[0] == 'f') {
      string word;
      cin >> word;

      if(dictionary[string(word)]) {
        puts("yes");
      } else {
        puts("no");
      }
    }
  }
}
