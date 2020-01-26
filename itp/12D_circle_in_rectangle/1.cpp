#include<cstdio>
#include<iostream>
using namespace std;

// 長方形の上下左右で４つの領域の境界条件を考える。

int main() {
  int W, H, x, y, r;
  string result;
  int rectangle_top, rectangle_right, rectangle_bottom, rectangle_left;
  int circle_top, circle_right, circle_bottom, circle_left;

  scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);

  rectangle_top = H;
  rectangle_right = W;
  rectangle_bottom = 0;
  rectangle_left = 0;

  circle_top = y + r;
  circle_right = x + r;
  circle_bottom = y - r;
  circle_left = x - r;

  if (
    circle_top <= rectangle_top &&
    circle_right <= rectangle_right &&
    circle_bottom >= rectangle_bottom &&
    circle_left >= rectangle_left
  ) {
    result = "Yes";
  } else {
    result = "No";
  }

  printf("%s\n", result.c_str());
}
