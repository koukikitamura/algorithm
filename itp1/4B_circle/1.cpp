#include<cstdio>
#include<cmath>

int main() {
  double radius;
  double area, circumference;

  // %d => int or short
  // %f => float
  // %lf => double
  // %c => char
  // %s => char *
  scanf("%lf", &radius);

  area = radius * radius * M_PI;
  circumference = 2 * radius * M_PI;

  printf("%lf %lf\n", area, circumference);
}
