#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LENGTH 100

// minとswap関数はalgorithmライブラリ

int selection_sort(int array[], int size) {
  int swap_count = 0;

  for(int i = 0; i < size - 1; i++) {
    int min_index = i;

    for(int j = i + 1; j < size; j++) {
      if (array[min_index] > array[j]) {
        min_index = j;
      }
    }

    if (i != min_index) {
      swap(array[i], array[min_index]);
      swap_count++;
    }
  }

  return swap_count;
}

int main() {
  int size, list[MAX_LENGTH];
  int swap_count;

  scanf("%d", &size);
  for(int i = 0; i < size; i++) {
    scanf("%d", &list[i]);
  }

  swap_count = selection_sort(list, size);

  for(int i = 0; i < size; i++) {
    printf("%d", list[i]);
    if (i != size - 1) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", swap_count);
}
