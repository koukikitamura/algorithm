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

struct UnionFind {
  V<int> p;

  UnionFind(int n) {
    p.resize(n);
    rep(i, n) {
      p[i] = i;
    }
  }

  int root(int i) {
    if(p[i] == i) {
      return i;
    }

    return p[i] = root(p[i]);
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);

    if(rx == ry) return;
    p[rx] = ry;
  }
};

int main() {
  int n, q;

  cin >> n >> q;

  UnionFind uf(n);

  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if(com == 0) {
      uf.unite(x, y);
    } else if(com == 1) {
      if(uf.same(x, y)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}