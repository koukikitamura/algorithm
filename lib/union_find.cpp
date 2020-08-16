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

  // Make set
  UnionFind(int n) {
    p.resize(n);
    rep(i, n) p[i] = i;
  }

  // Union
  void unite(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);

    p[root_a] = root_b;
  }

  // Find
  int root(int i) {
    if(p[i] == i) {
      return i;
    }
    return p[i] = root(p[i]);
  }

  bool same(int a, int b) {
    return root(a) == root(b);
  }
};