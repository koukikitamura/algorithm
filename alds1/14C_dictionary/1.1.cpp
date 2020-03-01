#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#define COMMAND_MAX_SIZE 7
#define WORD_MAX_SIZE 12
using namespace std;

// 記憶領域にはスタックとヒープがある。
// ## スタック領域
// - コンパイラやOSが自動割り当て、解放を行う。
// - サイズはプログラムをコンパイル、リンクする時点で決まっている。
// - ブロック内のローカル変数はスタック
//
// ## ヒープ領域
// - アプリケーションが必要になった時に確保し、不要になったら解放する。
// - サイズは確保する際に指定るする。
// - mallacやcallocはヒープ領域にメモリを確保する。

// スタックはあからじめサイズを決める必要があるので、最大値を想定して確保するため無駄な領域を確保せざるを得ない場合がある。
// スタック領域はOSやコンパイラによるが1MB ~ 数MB程度なので、配列の要素数が1,000,000要素程度になるとスタックオーバーフローを起こす。
// intが32bit(4byte)の場合4MBほどになり確保されているスタック領域から溢れ出してしまう。

// Aは'0'でなく’1'
map<char, int> char_to_int = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

int convert_word_to_num(char word[]) {
  int word_size = strlen(word);
  int num = 0;

  for(int i = 0; i < word_size; i++) {
    num += char_to_int[word[i]] * pow(char_to_int.size(), i);
  }

  return num;
}


int main() {
  int command_num;
  // 4^12 == 16777216 is true
  static bool dictionary[16777216] = {};

  scanf("%d", &command_num);

  for(int i = 0; i < command_num; i++) {
    char command[COMMAND_MAX_SIZE + 1];
    scanf("%s", command);

    if(command[0] == 'i') {
      char word[WORD_MAX_SIZE + 1];
      scanf("%s", word);

      dictionary[convert_word_to_num(word)] = true;
    } else if(command[0] == 'f') {
      char word[WORD_MAX_SIZE + 1];
      scanf("%s", word);

      bool is_found = dictionary[convert_word_to_num(word)];

      if (is_found) {
        puts("yes");
      } else {
        puts("no");
      }
    }
  }
}
