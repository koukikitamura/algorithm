#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
  double sqrt_num = sqrt(num);

  for(int i = 2; i <= sqrt_num; i++) {
    if(num % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int number_num;

  cin >> number_num;

  int prime_count = 0;
  for(int i = 0; i < number_num; i++) {
    int target;
    cin >> target;
    if(is_prime(target)) {
      prime_count++;
    }
  }

  cout << prime_count << endl;
}