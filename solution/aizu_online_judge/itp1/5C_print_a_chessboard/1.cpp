#include<cstdio>

int main() {
  int height, width;

  while(true) {
    scanf("%d %d", &height, &width);

    if(height == 0 && width == 0) {
      break;
    }

    for(int i = 0; i < height; i++) {
      char current_char = (i % 2 == 0) ? '#' : '.';

      for(int j = 0; j < width; j++) {
        printf("%c", current_char);

        current_char = (current_char == '#') ? '.' : '#';
      }
      printf("\n");
    }

    printf("\n");
  }
}
