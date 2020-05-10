#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int datasets_num;
  int datasets[1000];

  while(true) {
    double deviation;
    double variance = 0;
    double avarage = 0;
    double sum = 0;
    cin >> datasets_num;

    if(datasets_num == 0) {
      break;
    }

    for(int i = 0; i < datasets_num; i++) {
      int data;
      cin >> datasets[i];
      sum += datasets[i];
    }

    avarage = sum / datasets_num;
    for(int i = 0; i < datasets_num; i++){
      variance += pow((avarage - datasets[i]), 2);
    }
    variance /= (double)datasets_num;

    deviation = sqrt(variance);

    printf("%f\n", deviation);
  }
}
