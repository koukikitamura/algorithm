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
  int a, b, c;
  int inc_a, inc_b, inc_c;

  cin >> a >> b >> c;
  inc_a = a;
  inc_b = b;
  inc_c = c;

  int a_count, b_count, c_count;
  a_count = b_count = c_count = 0;

  int before_max = max(a, max(b, c));
  a_count += (before_max - a) / 2;
  b_count += (before_max - b) / 2;
  c_count += (before_max - c ) / 2;
  inc_a += a_count * 2;
  inc_b += b_count * 2;
  inc_c += c_count * 2;

  int after_max = max(inc_a, max(inc_b, inc_c));
  int after_min = min(inc_a, min(inc_b, inc_c));
  int ans = a_count + b_count + c_count;

  if(after_min != after_max) {
    int min_count = 0;
    if(inc_a == after_min) {
      min_count++;
    }
    if(inc_b == after_min) {
      min_count++;
    }
    if(inc_c == after_min) {
      min_count++;
    }
    if(min_count == 1) {
      ans += 2;
    } else if(min_count == 2) {
      ans += 1;
    }
  }

  cout << ans << endl;
}