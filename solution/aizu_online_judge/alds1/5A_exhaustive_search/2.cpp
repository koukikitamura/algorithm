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

V<int> a;


bool solve(int tail, int left_num) {
  if(left_num == 0) {
    return true;
  }
  if(left_num < 0 || tail > a.size()) {
    return false;
  }

  // Use
  if(solve(tail + 1, left_num - a[tail])) {
    return true;
  };
  // Not use
  if(solve(tail + 1, left_num)) {
    return true;
  }

  return false;
}

int main() {
  int n;
  int q;

  cin >> n;
  a.resize(n);
  rep(i, n) {
    cin >> a[i];
  }
  cin >> q;

  rep(i, q) {
    int m;
    cin >> m;

    bool can = solve(0, m);

    if(can) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}