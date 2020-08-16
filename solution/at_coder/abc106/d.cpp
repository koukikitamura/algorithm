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

V<V<int>> accum;

int main() {
  // n = 都市の個数
  // m = 列車の数
  int n, m, query;
  cin >> n >> m >> query;

  accum = V<V<int>>(n + 1, V<int>(n + 1, 0));

  // build accum
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    accum[l][r] += 1;
  }
  repf(i, 1, n + 1) {
    repf(j, 1, n + 1) {
      accum[i][j] += accum[i][j - 1] + accum[i - 1][j] - accum[i - 1][j - 1];
    }
  }

  rep(i, query) {
    int p, q;
    cin >> p >> q;
    int ans = accum[q][q] - accum[p - 1][q] - accum[q][p - 1] + accum[p - 1][p - 1];

    cout << ans << endl;
  }
}
