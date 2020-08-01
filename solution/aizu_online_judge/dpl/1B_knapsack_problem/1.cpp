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

struct Pro {
  int v;
  int w;
};

int capa;
int ans = 0;
V<Pro> p;

int main() {
  int n, capa;
  cin >> n >> capa;
  V<int> v(n), w(n);

  rep(i, n) {
    cin >> v[i] >> w[i];
  }

  // dp[品物][重さ] = 価値
  V<V<int>> dp(n + 1, V<int>(capa + 1));
  rep(i ,capa + 1) {
    dp[0][i] = 0;
  }

  rep(i, n) {
    rep(j, capa + 1) {
      if(j - w[i] >= 0) {
        // 同じものを使ってはいけないから dp[i + 1][j - w[i]] ではない
        dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  cout << dp[n][capa] << endl;
}
