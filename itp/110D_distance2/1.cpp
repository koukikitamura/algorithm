#include <iostream>
#include <cmath>
#define MAX_DIMENTION 100
#define DIMENSION_INFINIT -1
using namespace std;

double distance(int p, int vector1[], int vector2[], int dimension) {
  if(p == DIMENSION_INFINIT) {
    double max = vector1[0] - vector2[0];
    if (max < 0) {
      max = -max;
    }

    for(int i = 1; i < dimension; i++) {
      int each_distance = vector1[i] - vector2[i];
      if(each_distance < 0) {
        each_distance = -each_distance;
      }

      if(max < each_distance) {
        max = each_distance;
      }
    }

    return max;
  }


  double sum = 0;
  for(int i = 0; i < dimension; i++) {
  int elem_distance = vector1[i] - vector2[i];
  if (elem_distance < 0) {
    elem_distance = -elem_distance;
  }

    sum += pow(elem_distance , p);
  }

  return pow(sum, 1 / (double)p);
}

int main() {
  int dimension;
  int vector1[MAX_DIMENTION], vector2[MAX_DIMENTION];

  cin >> dimension;
  for(int i = 0; i < dimension; i++) {
    cin >> vector1[i];
  }
    for(int i = 0; i < dimension; i++) {
    cin >> vector2[i];
  }

  double p1_distance = distance(1, vector1, vector2, dimension);
  double p2_distance = distance(2, vector1, vector2, dimension);
  double p3_distance = distance(3, vector1, vector2, dimension);
  double p4_distance = distance(DIMENSION_INFINIT, vector1, vector2, dimension);

  printf("%f\n", p1_distance);
  printf("%f\n", p2_distance);
  printf("%f\n", p3_distance);
  printf("%f\n", p4_distance);
}
