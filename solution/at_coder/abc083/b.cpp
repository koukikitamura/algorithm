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
  int a, b;
  cin >> n >> a >> b;

  int ans = 0;
  repf(i, 1, n + 1) {
    int sum = 0;
    int left = i;

    while(left > 0) {
      sum += left % 10;

      left /= 10;
    }

    if(sum >= a && sum <= b) {
      ans += i;
    }
  }

  cout << ans << endl;
}