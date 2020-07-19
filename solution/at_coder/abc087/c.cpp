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
  V<V<int>> field(2, V<int>(n, 0));
  rep(i, 2) {
    rep(j, n) {
      cin >> field[i][j];
    }
  }

  int max_candy = 0;
  rep(to_buttom_i, n) {
    int current_i = 0;
    int current_j = 0;
    int candy_count = 0;

    rep(i, n + 1) {
      candy_count += field[current_i][current_j];

      if(current_i == 1 && current_j == n - 1) {
        break;
      }

      if(i == to_buttom_i) {
        current_i++;
      } else {
        current_j++;
      }
    }

    max_candy = max(max_candy, candy_count);
  }

  cout << max_candy << endl;
}