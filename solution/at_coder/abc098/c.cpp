#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  V<int> w(n + 1, 0);
  V<int> e(n + 1, 0);

  repf(i, 0, n) {
    w[i + 1] += w[i] + (s[i] == 'W' ? 1 : 0);
    e[i + 1] += e[i] + (s[i] == 'E' ? 1 : 0);
  }

  int min_reverse = n;
  rep(i, n) {
    int west_reverse_count = w[i] - w[0];
    int east_reverse_count = e[n] - e[i + 1];

    min_reverse = min(min_reverse, west_reverse_count + east_reverse_count);
  }

  cout << min_reverse << endl;
}
