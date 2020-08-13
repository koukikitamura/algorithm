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
  while(true) {
    int n;
    cin >> n;

    if(n == 0) {
      break;
    }

    V<int> a(n);

    rep(i, n) {
      cin >> a[i];
    }

    V<V<int>> dp(n, V<int>(n));
    rep(i, n) {
      dp[i][i] = 0;
      int j = i + 1;
    }

    int len = 2;
    for(int i = 0; i + len <= n; i++)  {
      int j = i + len - 1;

      if(abs(a[i] - a[j]) <= 1) {
        dp[i][j] = 2;
      } else {
        dp[i][j] = 0;
      }
    }

    for(len = 3; len <= n; len++) {
      for(int i = 0; i + len <= n; i++) {
        int j = i + len - 1;

        int cand1 = 0;
        if(dp[i + 1][j - 1] == len - 2) {
          cand1 = len - 2;

          if(abs(a[i] - a[j]) <= 1) {
            cand1 += 2;
          }
        }


        int cand2 = 0;
        repf(k, i, j) {
          cand2 = max(cand2, dp[i][k] + dp[k + 1][j]);
        }

        dp[i][j] = max(cand1, cand2);
      }
    }
    cout << dp[0][n - 1] << endl;
  }
}