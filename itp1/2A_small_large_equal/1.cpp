#include<cstdio>
#include<iostream>
using namespace std;

int main() {
  int a, b;
  string relation;

  scanf("%d %d", &a, &b);

  if (a < b) {
    relation = "<";
  } else if (a > b) {
    relation = ">";
  } else {
    relation = "==";
  }

  printf("a %s b\n", relation.c_str());
}
