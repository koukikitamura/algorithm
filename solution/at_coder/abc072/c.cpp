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
  V<int> a;
  map<int, int> candidate_x;
  cin >> n;
  a.resize(n);

  rep(i, n) {
    int elem;
    cin >> elem;

    a[i] = elem;

    candidate_x[elem - 1] = 0;
    candidate_x[elem] = 0;
    candidate_x[elem + 1] = 0;
  }

  // Count
  rep(i, n) {
    int elem = a[i];
    candidate_x[elem - 1]++;
    candidate_x[elem]++;
    candidate_x[elem + 1]++;
  }

  // Find max
  int max_x_count = 0;
  for(auto it = candidate_x.begin(); it != candidate_x.end(); it++) {
    max_x_count = max(it->second, max_x_count);
  }

  cout << max_x_count << endl;
}