#include<iostream>
#include<cmath>

using namespace std;


// 次のようにすると、小数点3桁目(含む)までしか出力されない。
// double real_number;
// cout << real_number;

int main() {
  double x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;

  double distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

  printf("%f\n", distance);
}
