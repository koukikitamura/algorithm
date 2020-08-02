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

struct Edge {
  int to;
  int cost;

  bool operator> (const Edge &other) const {
    return cost > other.cost;
  }
};

V<V<Edge>> graph;

const int inf = INT32_MAX;

int solve(int from, int to) {
  V<bool> seen(graph.size(), false);
  V<int> dist(graph.size(), inf);
  priority_queue<Edge, V<Edge>, greater<Edge>> todo;

  dist[from] = 0;
  todo.push({from, dist[from]});

  while(!todo.empty()) {
    Edge current = todo.top();
    todo.pop();
    if(current.cost > dist[current.to]) continue;

    seen[current.to] = true;
    for(auto next : graph[current.to]) {
      if(seen[next.to]) continue;

      if(dist[current.to] + next.cost < dist[next.to]) {
        dist[next.to] = dist[current.to] + next.cost;
        todo.push({next.to, dist[next.to]});
      }
    }
  }

  if(dist[to] == inf) {
    return -1;
  }

  return dist[to];
}

int main() {
  int n, k;
  cin >> n >> k;

  graph.resize(n);

  rep(i, k) {
    int cmd;
    cin >> cmd;

    // 注文
    if(cmd == 0) {
      int a, b;
      cin >> a >> b;
      a--; b--;

      cout << solve(a, b) << endl;
    }
    // 運行開始
    if(cmd == 1) {
      int c, d, e;
      cin >> c >> d >> e;
      c--; d--;
      graph[c].push_back({d, e});
      graph[d].push_back({c, e});
    }

  }
}
