#include <cstdio>
#define MAX_COLUMN_SIZE 100

int main() {
  int row_size, column_size;
  int column_sum[MAX_COLUMN_SIZE] = {};

  scanf("%d %d%*c", &row_size, &column_size);

  for(int i = 0; i < row_size; i++) {
    int row_sum = 0;

    for(int j = 0; j < column_size; j++) {
      int sell;
      scanf("%d", &sell);
      printf("%d ", sell);

      row_sum += sell;
      column_sum[j] += sell;

      if(j == column_size - 1) {
        printf("%d", row_sum);
        printf("\n");
      }
    }
  }

  int row_sum = 0;
  for(int i = 0; i < column_size; i++) {

    printf("%d ", column_sum[i]);

    row_sum += column_sum[i];

    if(i == column_size - 1) {
      printf("%d", row_sum);
      printf("\n");
    }
  }
}
