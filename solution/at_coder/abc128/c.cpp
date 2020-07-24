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
  // n = スイッチ
  // m = 電球
  int n, m;
  cin >> n >> m;
  V<V<int>> s_list;
  V<int> p_list;
  s_list.resize(m);
  p_list.resize(m);

  rep(i, m) {
    int k;
    cin >> k;
    s_list[i].resize(k);
    rep(ki, k) {
      cin >> s_list[i][ki];
    }
  }
  rep(i, m) {
    cin >> p_list[i];
  }

  // n個数のスイッチのon off
  int all_lights_up_count = 0;
  rep(bit, 1 << n){
    V<bool> s_on(s_list.size(), false);

    rep(i, n) {
      if(bit >> i & 1) {
        s_on[i] = true;
      }
    }

    bool all_lights_up = true;
    rep(i, s_list.size()) {
      int switch_on_count = 0;

      rep(j, s_list[i].size()) {
        int s_label = s_list[i][j];
        if(s_on[s_label - 1]) {
          switch_on_count++;
        }
      }

      if(switch_on_count % 2 != p_list[i]) {
        all_lights_up = false;
        break;
      }
    }

    if(all_lights_up) {
      all_lights_up_count++;
    }
  }

  cout << all_lights_up_count << endl;
}
