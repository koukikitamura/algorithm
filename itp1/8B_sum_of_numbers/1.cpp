#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int calc_sum_digits(string num) {
  int sum_digits = 0;

  for(int i = 0; i < num.size(); i++) {
    sum_digits += num[i] - '0';
  }

  return sum_digits;
}

int main(){
  while(true) {
    string num;
    cin >> num;

    if(num == "0") {
      break;
    }

    int sum_digits = calc_sum_digits(num);

    printf("%d\n", sum_digits);
  }
}
