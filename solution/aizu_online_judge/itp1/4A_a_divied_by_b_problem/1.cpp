#include<cstdio>

int main() {
  int a, b;
  int quotient_int;
  int remainer;
  double quotient_double;

  scanf("%d%d", &a, &b);

  quotient_int = a / b;
  remainer = a % b;
  quotient_double = (double)a / (double)b;

  printf(
    "%d %d %f\n",
    quotient_int,
    remainer,
    quotient_double // golang でないので、最後に "," はいらない
  );
}
