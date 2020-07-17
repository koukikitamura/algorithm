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
  int n, a, b;

  cin >> n >> a >> b;

  string ans;
  int between_num = (b - 1) - a;

  if(between_num % 2 == 1) {
    ans = "Alice";
  } else {
    ans = "Borys";
  }

  cout << ans << endl;
}
