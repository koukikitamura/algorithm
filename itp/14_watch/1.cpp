#include<cstdio>
#define SECOND_PER_HOUR (60 * 60)
#define SECOND_PER_MINUTE 60

int main() {
  int current_time_sec;
  int left_sec;
  int h, m, s;

  scanf("%d", &current_time_sec);

  h = current_time_sec / SECOND_PER_HOUR;
  left_sec = current_time_sec - h * SECOND_PER_HOUR;

  m = left_sec / SECOND_PER_MINUTE;
  left_sec = left_sec - m * SECOND_PER_MINUTE;

  s = left_sec;

  printf("%d:%d:%d\n", h , m, s);
}
