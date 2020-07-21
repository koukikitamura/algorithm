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
  int n, x;

  while(true) {
    cin >> n >> x;
    if(n == 0 && x == 0) {
      break;
    }

    int count = 0;
    repf(i, 1, n + 1) {
      repf(j, i + 1, n + 1) {
        repf(k, j + 1, n + 1) {
          if(i + j + k == x) {
            count++;
          }
        }
      }
    }

    cout << count << endl;
  }
}