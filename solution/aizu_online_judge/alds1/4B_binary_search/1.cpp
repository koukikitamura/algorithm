#include<cstdio>
#define MAX_SET_SIZE 100000

// 配列の引数はポインタとしてdebuggeに表示されるがcastすれば、配列の中身を見れる。
// *(int(*)[10])source

bool is_find_by_binary_search(int source[], int source_size, int target) {
  int headIndex = 0, tailIndex = source_size;

  while(headIndex < tailIndex) {
    int midIndex = (headIndex + tailIndex) / 2;

    if(source[midIndex] == target) {
      return true;
    }

    if(target < source[midIndex]) {
      tailIndex = midIndex;
    } else {
      headIndex = midIndex + 1;
    }
  }

  return false;
}

int main() {
  int S[MAX_SET_SIZE];
  int size_s;
  int size_t;

  scanf("%d", &size_s);
  for(int i = 0; i < size_s; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &size_t);
  int t_elem;
  int included_count = 0;
  for(int i = 0; i < size_t; i++) {
    scanf("%d", &t_elem);

    if(is_find_by_binary_search(S, size_s, t_elem)) {
      included_count++;
    }
  }

  printf("%d\n", included_count);
}
