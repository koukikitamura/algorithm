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
  cin >> n;
  V<ll> a(n + 1), b(n);

  rep(i, n + 1) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }

  ll prev_left = 0;
  ll count = 0;
  rep(i, n + 1) {
    ll monster_num = a[i];

    count += min(monster_num, prev_left);
    monster_num -= min(monster_num, prev_left);
    if(i < n) {
      count += min(monster_num , b[i]);
      prev_left = b[i] - min(monster_num , b[i]);
      monster_num -= min(monster_num , b[i]);
    }
  }

  cout << count << endl;
}