#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define COMMAND_MAX_SIZE 7 + 1
#define WORD_MAX_SIZE 12 + 1
using namespace std;
using Dictionary = vector<string>;

// *************************
// *  Time Limit Exceeded  *
// *************************
// 線形探索ではなく、二分探索を使う。
//
// stringではなく char []を使うと、自分でメモリを動的に確保する必要がある。
// Cだと配列のサイズは始めに決めなればならない、したがって想定される最大の要素数で確保する必要がある。
// 要素数が1,000,000の配列を最初に確保するとデバッガーが重くなる。
// insertとdeleteをするときは自分で管理するかは別として動的にメモリを確保するのが無難。

// string、vector、structも値渡し。

void insert(Dictionary *dictionary, string word) {
  (*dictionary).push_back(word);
}

bool find(Dictionary dictionary, string target_word) {
  for(auto it = dictionary.begin(); it != dictionary.end(); it++) {
    if(*it == target_word) {
      return true;
    }
  }

  return false;
}

int main() {
  int command_num;
  Dictionary dictionary;
  scanf("%d", &command_num);

  for(int i = 0; i < command_num; i++) {
    char command[COMMAND_MAX_SIZE];
    scanf("%s", command);

    if(0 == strncmp(command, "insert", 7)) {
      string word;
      cin >> word;

      insert(&dictionary, word);
    } else if(0 == strncmp(command, "find", 4)) {
      string word;
      cin >> word;

      bool is_found = find(dictionary, word);
      if(is_found) {
        puts("yes");
      } else {
        puts("no");
      }
    }
  }
}
