#include<cstdio>

// odd + odd => odd
// odd + even => even
// even + even => odd
// ２つのオペランドのeven or oddが同じだった時はoddになる。
// したがって、
// (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)
// は
// (i + j) % 2 == 0
// と置き換えられる

// (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)
// は２つの数値のeven or oddが同じという意味をもつ


int main() {
  int height, width;

  while(true) {
    scanf("%d %d", &height, &width);

    if(height == 0 && width == 0) {
      break;
    }

    for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
        if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
          printf("#");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }

    printf("\n");
  }
}
