#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); i++)
#define rrep(i, to) for (int i = (to) - 1; i >= 0; i--)
#define repf(i, from, to) for (int i = (from); i < (to); i++)
#define all(v) v.begin(), v.end()
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
  V<ll> a(3 * n);
  rep(i, 3 * n) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  ll ans = 0;
  for(int i = 1; i < 2 * n; i += 2) {
    ans += a[i];
  }

  cout << ans << endl;
}