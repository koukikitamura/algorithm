#include <cstdio>

// smallとmiddleの組み合わせを出して、largeが条件を満たすか計算するスタイル。

int count_combination(int n, int x) {
  int count = 0;

  for(int small = 1; small <= n - 2; small++) {
    for(int middle = small + 1; middle <= n - 1; middle++) {
      int large = x - (small + middle);

      if(large >= middle + 1 && large <= n) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n, x;

  while(true) {
    scanf("%d %d%*c", &n, &x);

    if(n == 0 && x == 0) {
      break;
    }

    int count = count_combination(n , x);
    printf("%d\n", count);
  }
}
