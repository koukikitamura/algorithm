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
  int n;
  int t;
  int a;
  V<int> h_list;

  cin >> n >> t >> a;
  h_list.resize(n);
  rep(i, n) {
    cin >> h_list[i];
  }

  int target_i = 0;
  double target_t = t - h_list[0] * 0.006;
  rep(i, n) {
    double current_t = t - h_list[i] * 0.006;

    if(abs(current_t - a) < abs(target_t - a)) {
      target_i = i;
      target_t = current_t;
    }
  }

  cout << target_i + 1 << endl;
}
