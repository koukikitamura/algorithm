#include <cstdio>
#include <cstring>
#define MAX_LETTERS_SIZE 101

int main() {
  char text[MAX_LETTERS_SIZE];
  char double_text[MAX_LETTERS_SIZE * 2];
  char pattern[MAX_LETTERS_SIZE];

  scanf("%s%*c", text);
  scanf("%s", pattern);

  strcpy(double_text, text);
  strcat(double_text, text);

  int text_size = strlen(text);
  int pattern_size = strlen(pattern);
  bool found;
  if(strstr(double_text, pattern) != NULL) {
    found = true;
  }

  if(found) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
