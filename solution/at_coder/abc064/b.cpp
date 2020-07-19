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

ll sovle(ll n, ll divisor) {
  if(n < 0) {
    return 0;
  }

  return n / divisor + 1;
}

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll ans = sovle(b, x) - sovle(a - 1, x);
  cout << ans << endl;
}