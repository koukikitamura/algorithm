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

  cin >> n;

  bool can = false;
  for(int i = 0; i * 4 <= n; i++) {
    int left_price = n - 4 * i;

    if(left_price % 7 == 0) {
      can = true;
      break;
    }
  }

  if(can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
