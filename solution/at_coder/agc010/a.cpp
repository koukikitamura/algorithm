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

  int odd_count = 0;
  rep(i, n) {
    if(a[i] % 2 == 1) {
      odd_count++;
    }
  }

  if(odd_count % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}