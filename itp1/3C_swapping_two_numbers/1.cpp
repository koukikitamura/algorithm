#include<cstdio>
#define MAX_DATASET_SIZE 3000

int main() {
  int x, y;

  for(int i = 0; i < MAX_DATASET_SIZE; i++) {
    scanf("%d %d\n", &x, &y);

    if (x == 0 && y == 0) {
      break;
    }

    // 理想的な条件でなかったら、理想的な条件にする
    if (!(x < y)) {
      int temp = x;
      x = y;
      y = temp;
    }

    printf("%d %d\n", x, y);
  }
}
