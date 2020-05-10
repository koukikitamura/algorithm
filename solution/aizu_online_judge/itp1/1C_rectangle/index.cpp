#include<cstdio>

int main() {
  int side1, side2;
  int area, perimeter;

  scanf("%d %d",&side1, &side2);

  area = side1 * side2;
  perimeter = (side1 + side2) * 2;

  printf("%d %d\n", area, perimeter);
}
