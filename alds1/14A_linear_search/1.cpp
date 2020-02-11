#include<cstdio>
#define MAX_SET_SIZE 10000
int main() {
  int S[MAX_SET_SIZE];
  int size_s, size_t;

  scanf("%d", &size_s);
  for(int i = 0; i < size_s; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &size_t);
  int t_elem;
  int included_count = 0;
  for(int i = 0; i < size_t; i++) {
    scanf("%d", &t_elem);

    for(int j = 0; j < size_s; j++) {
      if(t_elem == S[j]) {
        included_count++;
        break;
      }
    }
  }

  printf("%d\n", included_count);
}
