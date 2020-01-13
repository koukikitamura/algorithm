#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int main() {
  int R[MAX], n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> R[i];
  }

  int maxDiffR = R[1] - R[0];
  int minR = R[0];

  for (int i = 1; i < n; i++) {
    int currentDiffR = R[i] - minR;

    maxDiffR = max(maxDiffR, currentDiffR);
    minR = min(minR, R[i]);
  }

  cout << maxDiffR << endl;

  return 0;
}
