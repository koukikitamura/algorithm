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
  int n, m;
  cin >> n >> m;

  priority_queue<int, vector<int>, less<int>> a;

  rep(i, n) {
    int el_a;
    cin >> el_a;
    a.push(el_a);
  }

  rep(i, m) {
    int max_el = a.top();
    a.pop();

    int discount = max_el / 2;
    a.push(discount);
  }

  ll ans = 0;
  while(!a.empty()) {
    int el = a.top();
    a.pop();

    ans += el;
  }

  cout << ans << endl;
}