#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int count_less_or_equal_primes(int num) {
  vector<bool> is_primes(num + 1, true);

  is_primes[1] = false;

  double num_sqrt = sqrt(num);
  for(int i = 2; i <= num_sqrt; i++) {
    if(!is_primes[i]) {
      continue;
    }

    // Sift numbers
    for(int j = i + i; j <= num; j += i) {
      is_primes[j] = false;
    }
  }

  // Count left primes
  int prime_count = 0;
  for(int i = 1; i <= num; i++) {
    if(is_primes[i]) {
      prime_count++;
    }
  }
  return prime_count;
}

int main() {
  int num;

  while(cin >> num) {
    cout << count_less_or_equal_primes(num) << endl;
  }
}
