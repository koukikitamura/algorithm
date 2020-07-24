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
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());

  if(s < t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
