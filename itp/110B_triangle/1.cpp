#include<iostream>
#include<cmath>

using namespace std;

int main() {
  double side_a, side_b;
  double angle;
  double area;
  double circumference;
  double height;
  cin >> side_a >> side_b >> angle;

  height = sin(angle / 180 * M_PI) * side_b;
  double side_c = sqrt(side_a * side_a + side_b * side_b - 2 * side_a * side_b * cos(angle / 180 * M_PI));
  circumference = side_a + side_b + side_c;
  area = side_a * height * 0.5;

  printf("%f\n", area);
  printf("%f\n", circumference);
  printf("%f\n", height);
}
