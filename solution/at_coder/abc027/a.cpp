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
  int n, x;

  cin >> n >> x;
  V<int> a(n);

  rep(i, n) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int left = x;
  int count = 0;
  rep(i, n) {
    left -= a[i];

    if(left < 0) {
      break;
    }
    if(left == 0) {
      count++;
      break;
    }
    if(left > 0) {
      count++;
    }
  }
  if(left > 0) {
    count--;
  }

  cout << count << endl;
}