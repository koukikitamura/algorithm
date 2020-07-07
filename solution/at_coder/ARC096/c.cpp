#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
using P = pair<int, int>;


// Cの枚数を0 ~ max(X, Y) * 2で探索する
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int tmp_max_price = A * X + B * Y;
  rep(i, max(X, Y) * 2 + 1) {
    int price = i * C;

    price += A * max((X - i / 2), 0);
    price += B * max((Y - i / 2), 0);

    tmp_max_price = min(tmp_max_price, price);
  }

  cout << tmp_max_price << endl;
}