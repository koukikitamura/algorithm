#include <iostream>
#include <algorithm>

using namespace std;

long calc_gcd(long num1, long num2) {
  long greater = max(num1, num2);
  long less = min(num1, num2);
  long remainder = greater % less;

  if(remainder == 0) {
    return less;
  }

  return calc_gcd(less, remainder);
}


int main() {
  long num1, num2;

  while(cin >> num1 >> num2) {
    long gcd = calc_gcd(num1, num2);

    cout << gcd << ' ' << num1 * num2 /gcd << endl;
  }
}