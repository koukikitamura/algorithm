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

int n;
V<int> a;

ll solve(bool first_plus) {
  bool will_plus = first_plus;
  ll manip_count = 0;
  int sum = 0;
  rep(i, n) {
    int not_enough = 0;

    if(will_plus) {
      unless(sum + a[i] > 0) {
        not_enough = 1 - (sum + a[i]);
        manip_count += not_enough;
      }
    } else {
      unless(sum + a[i] < 0) {
        not_enough = -1 - (sum + a[i]);
        manip_count += abs(not_enough);
      }
    }

    sum += a[i] + not_enough;
    will_plus = !will_plus;
  }

  return manip_count;
}

int main() {
  cin >> n;
  a.resize(n);

  rep(i, n) {
    cin >> a[i];
  }

  ll first_plus = solve(true);
  ll first_minus = solve(false);
  cout << min(first_plus, first_minus) << endl;
}