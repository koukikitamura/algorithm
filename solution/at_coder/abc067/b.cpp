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
  int n, k;
  cin >> n >> k;
  V<int> l(n);

  rep(i, n) {
    cin >> l[i];
  }

  sort(l.rbegin(), l.rend()) ;

  int ans = 0;
  rep(i, k) {
    ans += l[i];
  }

  cout << ans << endl;
}