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
  int inf = INT32_MAX;
  int v, e;
  V<V<int>> dist;
  V<V<int>> dp;

  cin >> v >> e;

  dist.resize(v, V<int>(v, inf));

  rep(i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  dp.resize(1<<v, V<int>(v, inf));
  dp[0][0] = 0;
  repf(s, 1, 1<<v) {
    rep(last_i, v) {
      if(!(s & (1<<last_i))) {
        continue;
      }

      rep(j, v) {
        if(dp[s - (1<<last_i)][j] == inf || dist[j][last_i] == inf) {
          continue;
        }
        dp[s][last_i] = min(dp[s][last_i], dp[s - (1<<last_i)][j] + dist[j][last_i]);
      }
    }
  }

  int ans = dp[(1<<v) - 1][0];

  if(ans == inf) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}