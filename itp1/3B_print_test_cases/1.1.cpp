#include<cstdio>

int main() {
  int num;

  for(int i = 0; true; i++) {
    scanf("%d", &num);

    if (num == 0) {
      break;
    }

    printf("Case %d: %d\n", 1 + i, num);
  }
}
