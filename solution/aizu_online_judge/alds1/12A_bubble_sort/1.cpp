#include<cstdio>
#define MAX 100

void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

int bubble_sort(int array[], int size) {
  int swap_count = 0;

  // iの要素の順番を確定させる。
  for(int i = 0; i < size - 1; i++) {
    for(int j = size - 1; j > i; j--) {
      if (array[j - 1] > array[j]) {
        swap(&array[j - 1], &array[j]);
        swap_count++;
      }
    }
  }

  return swap_count;
}

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) {
      printf("%d", array[i]);
    if (i != size - 1) {
      printf(" ");
    }
  }
}

int main() {
  int size;
  int array[MAX];
  int swap_count;

  scanf("%d\n", &size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  swap_count = bubble_sort(array, size);
  print_array(array, size);

  printf("\n");
  printf("%d\n", swap_count);
}
