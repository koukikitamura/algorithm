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
  V<int> fibo;

  cin >> n;
  fibo.resize(n + 1);

  fibo[0] = fibo[1] = 1;

  repf(i, 2, n + 1) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  cout << fibo[n] << endl;
}
