#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_SENTENTCE_SIZE 1999
#define ALFABET_SIZE 26

// inputが「This is pen.」の時にscanf("%s", str)
// を使うとスペースまで読み取った、Thisしか受け取れない。

int main() {
  char str[MAX_SENTENTCE_SIZE];
  char alphabetical_count[ALFABET_SIZE] = {};

  while(true) {
    cin.getline(str, MAX_SENTENTCE_SIZE);
    if(cin.eof()) {
      break;
    }

    int str_size = strlen(str);

    // count
    for(int i = 0; i < str_size; i++) {
      char letter = tolower(str[i]);

      if(!(letter >= 'a' && letter <= 'z')) {
        continue;
      };

      alphabetical_count[letter - 'a'] += 1;
    }
  }
  // output
  for(int i = 0; i < ALFABET_SIZE; i++) {
    printf("%c : %d\n", i + 'a', alphabetical_count[i]);
  }
}
