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

int main() {
  int n, m;
  unordered_map<string, int> count;

  cin >> n;
  rep(i, n) {
    string str;
    cin >> str;

    count[str] += 1;
  }

  cin >> m;
  rep(i, m) {
    string str;
    cin >> str;

    count[str] -= 1;
  }

  int max_count = 0;

  for(auto it = count.begin(); it != count.end(); it++) {
    max_count = max(max_count, it->second);
  }

  cout << max_count << endl;
}
