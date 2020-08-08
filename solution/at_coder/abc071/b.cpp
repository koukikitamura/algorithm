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
  string s;
  cin >> s;

  unordered_map<char, int> count;

  rep(i, s.size()) {
    count[s[i]]++;
  }

  char ans = -1;
  rep(i, 26) {
    char ch = 'a' + i;

    if(count[ch] == 0) {
      ans = ch;
      break;
    }
  }

  if(ans == -1) {
    cout << "None" << endl;
  } else {
    cout << ans << endl;
  }
}