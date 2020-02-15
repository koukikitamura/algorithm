#include<cstdio>
#define MAX_SIZE 100

int main() {
  int size, numbers[MAX_SIZE];

  scanf("%d", &size);

  for(int i = 0; i < size; i++) {
    scanf("%d", &numbers[i]);
  }

  for(int i = size -1; i >= 0; i--) {
    printf("%d", numbers[i]);

    if(i != 0) {
      printf(" ");
    }
  }

  printf("\n");
}
