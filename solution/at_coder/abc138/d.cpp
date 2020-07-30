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

struct Node {
  ll value;
  V<int> adj;
};

V<Node> graph;
V<bool> visited;

// DFS
void accum(int current_i, ll value) {
  visited[current_i] = true;
  graph[current_i].value += value;

  for(auto next_i : graph[current_i].adj) {
    if(visited[next_i]) {
      continue;
    }

    accum(next_i, graph[current_i].value);
  }
}

int main() {
  int n, q;
  cin >> n >> q;

  graph.resize(n);
  visited.resize(n);

  rep(i, n - 1) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    graph[from].value = 0;
    graph[from].adj.push_back(to);
    graph[to].adj.push_back(from);
    visited[from] = false;
  }

  rep(i, q) {
    int to;
    ll x;
    cin >> to >> x;
    to--;
    graph[to].value += x;
  }
  accum(0, 0);

  rep(i, n) {
    cout << graph[i].value << " ";
  }
  cout << endl;
}
