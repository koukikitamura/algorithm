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
  int h, w;
  cin >> h >> w;
  V<string> board(h, "");
  rep(i, h) {
    cin >> board[i];
  }

  rep(hi, h) {
    rep(wi, w) {
      if(board[hi][wi] == '#') {
        continue;
      }

      int bomb_count = 0;
      repf(hj, hi - 1, hi + 2){
        repf(wj, wi - 1, wi + 2) {
          if(hj >= 0 && hj < h && wj >= 0  && wj < w) {
            if(board[hj][wj] == '#') {
              bomb_count++;
            }
          }
        }
      }
      board[hi][wi] = '0' + bomb_count;
    }
  }

  rep(hi, h) {
    cout << board[hi] << endl;
  }
}