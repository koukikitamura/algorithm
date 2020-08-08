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

const int inf = INT32_MAX;

int main() {
  int n;
  cin >> n;
  V<ll> a(n);

  rep(i, n) {
    cin >> a[i];
  }

  V<V<ll>> dp(n, V<ll>(n));
  rep(i, n) {
    // joi
    if((n - 1) % 2 == 0) {
      dp[i][i] = a[i];
    } else {
      dp[i][i] = 0;
    }
  }

  int len = 2;
  while(len <= n) {
    for(int i = 0; i < n; i++) {
      int j = i + len - 1;

      if((n - len) % 2 == 0) {
        // joi
        ll cand1 = a[i] + dp[(i + 1) % n][j % n];
        ll cand2 = dp[i][(j - 1) % n] + a[j % n];
        dp[i][j % n] = max(cand1, cand2);
      } else {
        bool pick_left = a[i] > a[j % n];

        if(pick_left) {
          dp[i][j % n] = dp[(i + 1) % n][j % n];
        } else {
          dp[i][j % n] = dp[i][(j - 1) % n];
        }
      }
    }
    len++;
  }

  ll ans = 0;
  rep(i, n) {
    ans = max(ans, dp[i][(i + n - 1) % n]);
  }
  cout << ans << endl;
}