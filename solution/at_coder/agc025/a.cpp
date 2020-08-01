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

  int min_sum = 1e9;
  rep(i, n + 1) {
    int a = i;
    int b = n - a;

    if(a < 1 || b < 1) {
      continue;
    }

    int sum = 0;
    while(a > 0) {
      sum += a % 10;
      a /= 10;
    }
    while(b > 0) {
      sum += b % 10;
      b /= 10;
    }

    min_sum = min(min_sum, sum);
  }

  cout << min_sum << endl;
}
