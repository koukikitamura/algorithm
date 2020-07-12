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
  int a, b, c, x;

  cin >> a >> b >> c >> x;
  int count = 0;
  rep(ai, a + 1) {
    if(ai * 500 > x) {
      break;
    }

    rep(bi, b + 1) {
      if(ai * 500 + bi * 100 > x) {
        break;
      }

      rep(ci, c + 1) {
        int sum = ai * 500 + bi * 100+ ci * 50;
        if(sum > x) {
          break;
        }

        if(sum == x) {
          count++;
        }
      }
    }
  }

  cout << count << endl;
}