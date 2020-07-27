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
  int k, s;

  cin >> k >> s;

  int count = 0;
  rep(x, k + 1) rep(y, k + 1) {
    int z = s - x - y;

    if(z >= 0 && z <= k) {
      count++;
    }
  }

  cout << count << endl;
}