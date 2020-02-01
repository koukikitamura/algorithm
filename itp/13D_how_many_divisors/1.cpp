#include<cstdio>
#include<algorithm>
using namespace std;

// divisors は約数
// 約数とは、整数や数式に対してそれを割り切るできる整数や数式のこと
// 約数はその数も入る
// e.g. 12の約数は 1, 2, 3, 4, 6, 12
int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  int divisors_count;

  for(int num = a; (num <= c && num <= b); num++) {
    int remainder = c % num;

    if (remainder == 0) {
      divisors_count++;
    }
  }

  printf("%d\n", divisors_count);
}
