#include <cstdio>

// 組み合わせを全て出して、条件に当てはまるか計算するスタイル。

int count_combination(int n, int x) {
  int count = 0;

  for(int small = 1; small < n - 2; small++) {
    for(int middle = small + 1; middle < n - 1; middle++) {
      for(int large = middle + 1; large <= n; large++) {
        if(small + middle + large == x) {
          count++;
        }
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
