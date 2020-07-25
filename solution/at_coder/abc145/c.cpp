#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); i++)
#define rrep(i, to) for (int i = to - 1; i >= 0; i--)
#define repf(i, from, to) for (int i = (from); i < (to); i++)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

struct Point {
  int x;
  int y;
};

double dist(Point from, Point to) {
  int dx = to.x - from.x;
  int dy = to.y - from.y;

  double dist = sqrt(dx * dx + dy * dy);
  return dist;
}

int main() {
  int n;
  V<Point> grid;
  cin >> n;
  grid.resize(n);

  rep(i, n) {
    cin >> grid[i].x >> grid[i].y;
  }
  V<int> p(n, 0);
  rep(i, n) {
    p[i] = i;
  }

  double len = 0;
  int count = 0;

  do {
    rep(i, n - 1) {
      int from = p[i];
      int to = p[i + 1];
      len += dist(grid[from], grid[to]);
    }
    count++;
  } while(next_permutation(p.begin(), p.end()));

  double ans = len / count;

  printf("%.9f\n", ans);
}
