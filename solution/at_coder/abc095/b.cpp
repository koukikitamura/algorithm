#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); i++)
#define rrep(i, to) for (int i = to - 1; i >= 0; i--)
#define repf(i, from, to) for (int i = (from); i < (to); i++)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n, x;
  V<int> m_list;

  cin >> n >> x;
  m_list.resize(n);
  rep(i, n) {
    cin >> m_list[i];
  }
  int left_x = x;
  int min_m = 1000;
  int ans = 0;
  rep(i, n) {
    left_x -= m_list[i];
    min_m = min(min_m, m_list[i]);
    ans++;
  }
  ans += left_x / min_m;

  cout << ans << endl;
}
