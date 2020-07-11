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

// 以下の物がある時間に置いてわかればその時間においてバスを出すべきかがわかる。
// それまでに乗車している人の人数
// それまでに乗車した人でもっとも早く乗車した時間

int main() {
  int n, c, k;
  V<int> t_list;

  cin >> n >> c >> k;
  t_list.resize(n);

  rep(i, n) {
    cin >> t_list[i];
  }
  sort(t_list.begin(), t_list.end());

  int passenger_num = 1;
  int wait_start_time = t_list[0];
  int bus_count = 0;

  repf(i, 1, n) {
    if(passenger_num < c &&  t_list[i] <= wait_start_time + k) {
      passenger_num++;
    } else {
      bus_count++;

      wait_start_time = t_list[i];
      passenger_num = 1;
    }
  }
  if(passenger_num > 0) {
    bus_count++;
  }

  cout << bus_count << endl;
}