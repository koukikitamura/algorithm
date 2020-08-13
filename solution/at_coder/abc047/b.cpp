#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); i++)
#define rrep(i, to) for (int i = (to) - 1; i >= 0; i--)
#define repf(i, from, to) for (int i = (from); i < (to); i++)
#define all(v) v.begin(), v.end()
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  V<V<bool>> white(h + 1, V<bool>(w + 1, true));

  // white[i][j]は正方形の右上を表す
  rep(i, n) {
    int x, y, a;
    cin >> x >> y >> a;

    if(a == 1) {
      rep(i, h + 1) {
        rep(j, x + 1) {
          white[i][j] = false;
        }
      }
    } else if (a == 2) {
      rep(i, h + 1) {
        repf(j, x + 1, w + 1) {
          white[i][j] = false;
        }
      }
    } else if (a == 3) {
      rep(i, y + 1) {
        rep(j, w + 1) {
          white[i][j] = false;
        }
      }
    } else if (a == 4) {
      repf(i, y + 1, h + 1) {
        rep(j, w + 1) {
          white[i][j] = false;
        }
      }
    }
  }

  int area = 0;

  repf(i, 1, h + 1) {
    repf(j, 1, w + 1) {
      if(white[i][j]) {
        area++;
      }
    }
  }

  cout << area << endl;
}