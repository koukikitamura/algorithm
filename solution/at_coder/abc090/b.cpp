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
  int a, b;

  cin >> a >> b;

  int count = 0;
  repf(i, a, b + 1) {
    string str = "";
    int n = i;
    while(n > 0) {
      str.push_back('0' + n % 10);
      n /= 10;
    }
    reverse(all(str));

    bool can = true;
    rep(j, str.size() / 2) {
      if(str[j] != str[str.size() - 1 - j]) {
        can = false;
        break;
      }
    }

    if(can) {
      count++;
    }
  }

  cout << count << endl;
}
