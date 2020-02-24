#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX_STRING_SIZE 1999
using namespace std;

// lowecase/uppercase 変換
// 'A' + 'a' - 'A' => 'a'
// 'B' + 'a' - 'A' => 'A' + 1 + 'a' - 'A' => 'a' + 1

// 標準入力に`cin`使っているなら、素直にstd::stringを使えよ感。

char reverse_case(char character) {
  if(character >= 'a' && character < 'z') {
    return character + ('A' - 'a');
  } else if (character >= 'A' && character <= 'Z') {
    return character + ('a' - 'A');
  }

  return character;
}

int main() {
  char str[MAX_STRING_SIZE];
  char conveted_str[MAX_STRING_SIZE];

  cin.getline(str, MAX_STRING_SIZE);
  int length = strlen(str);

  for(int i = 0; i < length; i++) {
    conveted_str[i] = reverse_case(str[i]);
  }
  conveted_str[length] = '\0';
  printf("%s\n", conveted_str);
}
