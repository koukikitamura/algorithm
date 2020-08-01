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

struct Point {
  int x;
  int y;
};

int main() {
  int r, c;
  cin >> r >> c;

  Point start, goal;
  cin >> start.x >> start.y;
  cin >> goal.x >> goal.y;
  start.x--;
  start.y--;
  goal.x--;
  goal.y--;

  V<V<char>> grid;
  grid.resize(r);
  rep(ri, r) {
    grid[ri].resize(c);
    rep(ci, c) {
      cin >> grid[ri][ci];
    }
  }

  V<V<int>> dist(r, V<int>(c, -1));
  V<V<bool>> seen(r, V<bool>(c, false));
  queue<Point> todo;

  dist[start.x][start.y] = 0;
  seen[start.x][start.y] = true;
  todo.push(start);

  V<Point> dxy_list = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  while(!todo.empty()) {
    Point current = todo.front();
    todo.pop();

    for(auto dxy : dxy_list) {
      Point next = {current.x + dxy.x, current.y + dxy.y};

      if(grid[next.x][next.y] == '#') {
        continue;
      }

      if(seen[next.x][next.y]) {
        continue;
      }

      seen[next.x][next.y] = true;
      dist[next.x][next.y] =  dist[current.x][current.y] + 1;
      todo.push(next);
    }
  }

  cout << dist[goal.x][goal.y] << endl;
}
