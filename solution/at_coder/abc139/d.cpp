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
  ll n;
  cin >> n;

  // 0 <= M < P ということを踏まえてると
  // Aを P = A - 1となるようにすれば Pに対するMが全て最大化される
  // したがって、1 ~ n - 1の和を求めれば良い
  n--;
  ll ans = n * (n + 1) / 2;

  cout << ans << endl;
}