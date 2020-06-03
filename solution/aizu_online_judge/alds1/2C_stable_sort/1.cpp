#include<cstdio>
#include<algorithm>

#define MAX_SIZE 36

struct Tramp{
  char mark;
  int number;
};

// 配列を引数に取る関数を切り出すと、デバッガで変数が配列のポインタしか見れないのでデバッグしにくい。

void bubble_sort(Tramp array[], int size) {
  for(int i = 0; i < size - 1; i++) {
    for(int j = size - 1; j > i; j--) {
      if(array[j].number < array[j - 1].number) {
        std::swap(array[j - 1], array[j]);
      }
    }
  }
}

void selection_sort(Tramp array[], int size) {
  for(int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if(array[j].number < array[min_index].number) {
        min_index = j;
      }
    }

    if(i != min_index) {
      std::swap(array[i], array[min_index]);
    }
  }
}

bool check_selection_stable(Tramp bubble[], Tramp selection[], int size) {
  for(int i = 0; i < size; i++) {
    if(
      selection[i].mark != bubble[i].mark ||
      selection[i].number != bubble[i].number
    ) {
      return false;
    }
  }
  return true;
}

void print_tramp(Tramp tramps[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%c%d", tramps[i].mark, tramps[i].number);
    if(i != size - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  int size;
  Tramp bubble_array[MAX_SIZE], selection_array[MAX_SIZE];
  scanf("%d%*c", &size);

  for(int i = 0; i < size; i++) {
    scanf("%c%d ", &bubble_array[i].mark, &bubble_array[i].number);
    selection_array[i].mark = bubble_array[i].mark;
    selection_array[i].number = bubble_array[i].number;
  }

  bubble_sort(bubble_array, size);
  selection_sort(selection_array, size);

  print_tramp(bubble_array, size);
  printf("Stable\n");
  print_tramp(selection_array, size);

  bool is_selection_stable = check_selection_stable(bubble_array, selection_array, size);
  if(is_selection_stable) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }
}
