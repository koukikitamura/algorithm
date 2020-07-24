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
  int n;
  string s;
  V<char> ch_list;
  repf(i, 0, 10) {
    ch_list.push_back('0' + i);
  }
  cin >> n >> s;

  int count = 0;
  rep(i, 10) rep(j, 10) rep(k, 10) {
    string pin = "" + ch_list[i] + ch_list[j] + ch_list[k];

    // Creatable
    int find_tail = 0;
    rep(i, n){
      if(s[i] == pin[find_tail]) {
        find_tail++;
      }
      if(find_tail == pin.size()) {
        break;
      }
    }

    // Find
    if(find_tail == pin.size()) {
      count++;
    }
  }

  cout << count << endl;
}