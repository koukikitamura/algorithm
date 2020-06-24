#include <iostream>
#include <algorithm>

using namespace std;


int calc_gcd(int num1, int num2) {
  int larger = max(num1, num2);
  int smaller = min(num1, num2);

  int remainder = larger % smaller;

  if(remainder == 0) {
    return smaller;
  }

  return calc_gcd(smaller, remainder);
}

int main() {
  int num1, num2;

  cin >> num1 >> num2;

  cout << calc_gcd(num1, num2) << endl;
}
