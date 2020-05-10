#include <cstdio>
#define BASE_NUM 10

// 整数の大きさに制限がない場合は、怪しい。
// long longでもオーバーフローするかも。
// 文字列の方が安全。

long long calc_sum_digits(long long num) {
  long long left_digits = num;
  long long sum_digits = 0;

  while(true) {
    if(left_digits == 0) {
      break;
    }
    sum_digits += left_digits % BASE_NUM;

    left_digits = left_digits / BASE_NUM;
  }

  return sum_digits;
}

int main() {
  while(true) {
    long long num;
    scanf("%lld", &num);
    if(num == 0) {
      break;
    }

    long long sum_disigs = calc_sum_digits(num);

    printf("%lld\n", sum_disigs);
  }
}
