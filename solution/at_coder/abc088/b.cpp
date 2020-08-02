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
  V<int> a(n);

  rep(i, n) {
    cin >> a[i];
  }

  int a_score, b_score;
  a_score = b_score = 0;

  rep(i, n) {
    if(i % 2 == 0) {
      a_score += a[i];
    } else {
      b_score += a[i];
    }
  }

  cout << a_score - b_score << endl;
}
