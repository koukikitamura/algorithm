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
  a.resize(n);
  rep(i, n) {
    cin >> a[i];
  }

  int min_elem = a[0];
  int max_elem = a[0];
  rep(i, n) {
    min_elem = min(min_elem, a[i]);
    max_elem = max(max_elem, a[i]);
  }

  cout << max_elem - min_elem << endl;
}
