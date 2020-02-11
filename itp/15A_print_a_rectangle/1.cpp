#include<cstdio>

int main() {
  int height, width;

  while(true) {
    scanf("%d %d", &height, &width);

    if(height == 0 && width == 0) {
      break;
    }

    for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
        printf("#");
      }
      printf("\n");
    }

    printf("\n");
  }
}
