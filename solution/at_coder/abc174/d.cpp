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
  string str;
  cin >> n >> str;

  int l, r;

  // rr...rww..w の形であれば良い
  l = 0;
  r = n - 1;
  int ans = 0;
  while(true) {
    while(l < n && str[l] == 'R') {
      l++;
    }

    while(l >= 0 && str[r] == 'W') {
      r--;
    }

    if(l <= r) {
      swap(str[l++], str[r--]);
      ans++;
    } else {
      break;
    }
  }

  cout << ans << endl;
}