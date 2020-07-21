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

bool check(int n) {
  int count = 0;

  repf(i, 1, n + 1) {
    if(count > 8) {
      break;
    }

    if(n % i == 0) {
      count++;
    }
  }

  return count == 8;
}

int main() {
  int n;
  cin >> n;

  int count_num = 0;

  repf(i, 1, n + 1) {
    if(i % 2 != 1) {
      continue;
    }
    if(check(i)) {
      count_num++;
    }
  }

  cout << count_num << endl;
}