#include<cstdio>
#include<cmath>
#define MAX_SIZE 10000

// 0 <= size <= 10000
// −1000000 <= Num <= 1000000
// 和がintの範囲を超える可能性がある

// long long => %lld

int main() {
  int size;
  int current_num;
  int min_num, max_num;

  long long sum;

  scanf("%d", &size);
  scanf("%d", &current_num);

  min_num = max_num = sum = current_num;

  for(int i = 1; i < size; i++) {
    scanf("%d", &current_num);

    if (current_num < min_num) {
      min_num = current_num;
    }

    if (current_num > max_num) {
      max_num = current_num;
    }

    sum += current_num;
  }

  printf("%d %d %lld\n", min_num, max_num, sum);
}
