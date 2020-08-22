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
  int n, w;
  cin >> n >> w;

  V<int> weights(n);
  V<int> values(n);
  rep(i, n) {
    cin >> values[i] >> weights[i] ;
  }

  V<int> dp(w + 1);
  dp[0] = 0;

  repf(i, 1, w + 1) {
    int cand = 0;

    rep(j, n) {
      if(i - weights[j] >= 0) {
        cand = max(cand, dp[i - weights[j]] + values[j]);
      }
    }

    dp[i] = cand;

  }

  cout << dp[w] << endl;
}
