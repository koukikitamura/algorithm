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

V<int> s;

int search(int target) {
  int head, tail;
  head = 0;
  tail = s.size();

  while(head < tail) {
    int mid = (tail + head) / 2;

    if(s[mid] == target) {
      return mid;
    }

    if(s[mid] < target) {
      head = mid + 1;
    } else {
      tail = mid;
    }
  }

  return -1;
}

int main() {
  int n, q;

  cin >> n;
  s.resize(n);
  rep(i, n) {
    cin >> s[i];
  }

  cin >> q;

  int ans = 0;
  rep(i, q) {
    int target;
    cin >> target;

    int index = search(target);

    if(index != -1) {
      ans++;
    }
  }

  cout << ans << endl;
}