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

int count_two_factor(int num) {
  int count = 0;
  int tmp_num = num;

  while(tmp_num % 2 == 0) {
    count++;
    tmp_num /= 2;
  }

  return count;
}

int main() {
  int n;
  V<int> a;
  cin >> n;
  a.resize(n);

  rep(i, n) {
    cin >> a[i];
  }

  int min_two_factor_count = 1e9;
  rep(i, n) {
    int current_count = count_two_factor(a[i]);
    min_two_factor_count = min(min_two_factor_count, current_count);
  }

  cout << min_two_factor_count << endl;
}