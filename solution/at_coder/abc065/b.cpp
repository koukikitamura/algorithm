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
  V<int> a;
  cin >> n;
  a.resize(n + 1);
  repf(i, 1, n + 1) {
    cin >> a[i];
  }

  int label = 1;
  int count = 0;
  bool found = false;
  while(true) {
    if(label == 2) {
      found = true;
      break;
    }
    if(count >= n - 1) {
      break;
    }

    count++;
    label = a[label];
  }

  if(found) {
    cout << count << endl;
  } else {
    cout << -1 << endl;
  }
}
