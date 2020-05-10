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
        bool isTop = i == 0;
        bool isRight = j == width - 1;
        bool isBottom = i == height - 1;
        bool isLeft = j == 0;

        if(isTop || isRight || isBottom || isLeft) {
          printf("#");
        } else {
          printf(".");
        }
      }

      printf("\n");
    };

    printf("\n");
  }
}
