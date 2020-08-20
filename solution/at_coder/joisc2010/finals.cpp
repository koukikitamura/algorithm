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
    int root_x = root(x);
    int root_y = root(y);
    p[root_x] = root_y;
  }
};

struct Edge {
  int u, v;
  int cost;

  bool operator<(const Edge &other) const {
    return cost < other.cost;
  }
};

int main() {
  // n = 都市の数
  // m = 道路の数
  // k = 開催都市の数
  int n, m, k;
  cin >> n >> m >> k;

  V<Edge> edges(m);

  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;

    edges[i] = {a, b, c};
  }

  sort(edges.begin(), edges.end());
  int cost = 0;
  int edge_count = 0;
  UnionFind uf(n);
  rep(i, m) {
    if(edge_count == (n - 1) - (k - 1)) {
      break;
    }

    Edge edge = edges[i];

    if(uf.same(edge.u, edge.v)) {
      continue;
    }

    edge_count++;
    cost += edge.cost;
    uf.unite(edge.u, edge.v);
  }

  cout << cost << endl;
}
