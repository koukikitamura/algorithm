#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n;
  cin >> n;
  V<int> a;
  a.resize(n);

  rep(i, n) {
    cin >> a[i];
  }

  int count = 1;
  bool uping = false;
  bool downing = false;

  repf(i, 1, n) {
    int diff = a[i] - a[i - 1];

    if(uping && diff < 0) {
      uping = false;
      count++;
      continue;
    }
    if(downing && diff > 0) {
      downing = false;
      count++;
      continue;
    }

    unless(uping || downing) {
      uping = diff > 0;
      downing = diff < 0;
    }
  }

  cout << count << endl;
}