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

int count_two_factor(ll num) {
  int count = 0;

  while(num % 2 == 0) {
    count++;
    num /= 2;
  }

  return count;
}

int main() {
  int n;
  V<ll> a;

  cin >> n;
  a.resize(n);
  rep(i, n) {
    cin >> a[i];
  }

  int min_two_factor = 1e9;
  rep(i, n) {
    min_two_factor = min(min_two_factor, count_two_factor(a[i]));
  }

  cout << min_two_factor << endl;
}
