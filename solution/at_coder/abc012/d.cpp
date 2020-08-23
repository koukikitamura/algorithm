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

int inf = INT32_MAX / 2;

int main() {
  // n = バスの数
  // m = 路線の数
  int n, m;
  cin >> n >> m;

  V<V<int>> dp(n, V<int>(n, inf));

  rep(i, m) {
    int a, b, t;
    cin >> a >> b >> t;
    a--; b--;
    dp[a][b] = dp[b][a] = t;
  }
  rep(i, n) {
    dp[i][i] = 0;
  }

  rep(k, n) {
    rep(i, n) {
      rep(j, n) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int ans = inf;

  rep(i, n) {
    int longest_time = 0;

    rep(j, n) {
      longest_time = max(longest_time, dp[i][j]);
    }

    ans = min(ans, longest_time);
  }

  cout << ans << endl;
}