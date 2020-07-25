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

int main() {
  string s;
  cin >> s;

  // find first A
  int head;
  rep(i, s.size()) {
    if(s[i] == 'A') {
      head = i;
      break;
    }
  }

  // find last Z
  int tail;
  rrep(i, s.size()) {
    if(s[i] == 'Z') {
      tail = i + 1;
      break;
    }
  }

  cout << tail - head << endl;
}
