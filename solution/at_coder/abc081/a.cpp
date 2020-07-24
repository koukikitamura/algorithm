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
  string s;
  cin >> s;

  int count = 0;
  rep(i, s.size()) {
    if(s[i] == '1') {
      count++;
    }
  }

  cout << count << endl;
}
