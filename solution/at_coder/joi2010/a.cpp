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
  // n = 宿場町の数, m = 日数
  int n, m;
  cin >> n >> m;

  // dist[0] は 0 => 1の距離
  V<ll> dist(n - 1);
  rep(i, n - 1) {
    cin >> dist[i];
  }

  V<int> plan(m);
  rep(i, m) {
    cin >> plan[i];
  }


  // accum[i] は宿場町iまでの距離
  V<ll> accum(n) ;
  accum[0] = 0;
  repf(i, 1, n) {
    accum[i] = accum[i - 1] + dist[i - 1];
  }

  int town_i = 0;
  ll sum = 0;
  rep(i, m) {
    int next_town_i = town_i + plan[i];

    sum += abs(accum[next_town_i] - accum[town_i]);

    town_i = next_town_i;
  }

  cout << (sum % (ll)1e5) << endl;
}