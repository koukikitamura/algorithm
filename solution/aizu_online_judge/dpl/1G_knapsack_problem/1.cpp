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

struct Product {
  int v, w;
};
V<Product> products;

int main() {
  int n, w;
  cin >> n >> w;
  products.resize(n);

  rep(i, n) {
    int weight, value;
    cin >> weight >> value;
    products[i] = { weight, value };
  }

  V<V<int>> dp(n + 1, V<int>(w + 1));

  rep(i, w + 1) {
    dp[0][i] = 0;
  }

  repf(i, 1, n + 1) {
    rep(j, w + 1) {
      auto p = products[i - 1];

      if(j - p.w >= 0) {
        dp[i][j] = max(dp[i - 1][j - p.w] + p.v, dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][w] << endl;
}
