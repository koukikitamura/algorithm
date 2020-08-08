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

  V<int> count(n, 0);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    count[a]++;
    count[b]++;
  }

  rep(i, n) {
    cout << count[i] << endl;
  }
}