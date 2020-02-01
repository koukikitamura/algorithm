#include<cstdio>
#define MAX_DATASET_SIZE 10000

int main() {
  int data_sets[MAX_DATASET_SIZE];

  for(int i = 0; i < MAX_DATASET_SIZE; i++) {
    scanf("%d", &data_sets[i]);

    if (data_sets[i] == 0) {
      break;
    }

    printf("Case %d: %d\n", i + 1, data_sets[i]);
  }
}
