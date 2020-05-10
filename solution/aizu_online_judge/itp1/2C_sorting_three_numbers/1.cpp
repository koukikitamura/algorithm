#include<cstdio>

void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

int main() {
  int first, second, third;

  scanf("%d %d %d", &first, &second, &third);

  if (second < first) {
    swap(&first, &second);
  }
  if (third < second) {
    swap(&second, &third);
  }
  if (second < first) {
    swap(&first, &second);
  }

  printf("%d %d %d\n", first, second, third);
}
