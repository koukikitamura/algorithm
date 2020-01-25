#include<cstdio>
#define SECOND_PER_HOUR (60 * 60)
#define SECOND_PER_MINUTE 60

int main() {
  int time_sec;
  int h, m ,s;

  scanf("%d", &time_sec);
  h = time_sec / SECOND_PER_HOUR;
  m = (time_sec % SECOND_PER_HOUR) / SECOND_PER_MINUTE;
  s = time_sec % SECOND_PER_MINUTE;

  printf("%d:%d:%d\n", h, m, s);
}
