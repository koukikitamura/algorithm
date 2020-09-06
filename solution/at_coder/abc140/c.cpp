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
  V<int> b;

  cin >> n;
  b.resize(n - 1);

  rep(i, n - 1) {
    cin >> b[i];
  }

  int ans = 0;
  rep(i, n) {
    int cand_a = INT32_MAX;

    if(i >= 0 && i < n - 1) {
      cand_a = min(cand_a, b[i]);
    }
    if(i - 1 >= 0 && i - 1 < n - 1) {
      cand_a = min(cand_a, b[i - 1]);
    }
    ans += cand_a;
  }

  cout << ans << endl;
}