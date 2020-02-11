#include<cstdio>
#define CARDINAL_NUMBER 10

bool isIncludeDigitThree(int num) {
  for(int left_num = num; left_num > 0; left_num /= 10) {
    int first_digit = left_num % 10;

    if(first_digit == 3) {
      return true;
    }
  }

  return false;
}

int main() {
  int num;
  scanf("%d", &num);

  for(int i = 1; i <= num; i++) {
    if (i % 3 == 0 || isIncludeDigitThree(i)) {
      printf(" %d" , i);
    };
  }

  printf("\n");
}
