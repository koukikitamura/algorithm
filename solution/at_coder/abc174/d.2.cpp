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
  string s;

  cin >> n >> s;

  int left_w = 0;
  int right_r = 0;
  rep(i, n) {
    if(s[i] == 'R') {
      right_r++;
    }
  }

  int ans = n;
  rep(border, n + 1) {
    int count = max(left_w, right_r);
    ans = min(ans, count);

    if(s[border] == 'R') {
      right_r--;
    } else {
      left_w++;
    }
  }

  cout << ans << endl;
}