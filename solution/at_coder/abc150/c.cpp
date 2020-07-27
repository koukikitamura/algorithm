#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); i++)
#define rrep(i, to) for (int i = to - 1; i >= 0; i--)
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
  int n;
  V<int> p;
  V<int> q;

  cin >> n;
  p.resize(n);
  q.resize(n);
  rep(i, n) {
    cin >> p[i];
  }
  rep(i, n) {
    cin >> q[i];
  }

  V<int> perm(n, 0);
  rep(i, n) {
    perm[i] = i + 1;
  }

  bool find_p = false;
  bool find_q = false;
  int a, b;
  int count = 0;
  do {
    count++;
    if(perm == p && !find_p) {
      a = count;
    }
    if(perm == q && !find_q) {
      b = count;
    }
  } while(next_permutation(all(perm)));

  cout << abs(a - b) << endl;
}