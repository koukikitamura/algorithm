#include <iostream>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

void print_point(Point point) {
  printf("%.8f %.8f\n", point.x, point.y);
}

double to_radian(double degree) {
  return M_PI * degree / 180;
}

void draw_inner_koch_curve(int depth, Point start_point, Point end_point) {
  if(depth < 1) {
    return;
  }


  Point one_thirds_point;
  Point two_thirds_point;

  // 回転行列
  one_thirds_point.x = start_point.x + (end_point.x - start_point.x) * (1 / 3.0);
  one_thirds_point.y = start_point.y + (end_point.y - start_point.y) * (1 / 3.0);
  two_thirds_point.x = start_point.x + (end_point.x - start_point.x) * (2 / 3.0);
  two_thirds_point.y = start_point.y + (end_point.y - start_point.y) * (2 / 3.0);

  Point rotation_point;
  double rotation_degree = 60;
  rotation_point.x =
    (two_thirds_point.x - one_thirds_point.x) * cos(to_radian(rotation_degree)) -
    (two_thirds_point.y - one_thirds_point.y) * sin(to_radian(rotation_degree)) +
    one_thirds_point.x;

  rotation_point.y =
    (two_thirds_point.x - one_thirds_point.x) * sin(to_radian(rotation_degree)) +
    (two_thirds_point.y - one_thirds_point.y) * cos(to_radian(rotation_degree)) +
    one_thirds_point.y;

  draw_inner_koch_curve(depth - 1, start_point, one_thirds_point);
  print_point(one_thirds_point);
  draw_inner_koch_curve(depth - 1, one_thirds_point, rotation_point);
  print_point(rotation_point);
  draw_inner_koch_curve(depth - 1, rotation_point, two_thirds_point);
  print_point(two_thirds_point);
  draw_inner_koch_curve(depth - 1, two_thirds_point, end_point);
};


int main() {
  Point start_point{0, 0}, end_point{100, 0};
  int depth;
  cin >> depth;


  print_point(start_point);
  draw_inner_koch_curve(depth, start_point, end_point);
  print_point(end_point);

}
