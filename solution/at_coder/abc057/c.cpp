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
  ll n;
  double sqrt_n;

  cin >> n;
  sqrt_n = sqrt(n);

  int tmp_min = log10(n) + 1;
  repf(i ,1, sqrt_n + 1) {
    if(n % i != 0){
      continue;
    }
    ll a = i;
    ll b = n / a;

    int current_min = max(
      log10(a) + 1,
      log10(b) + 1
    );

    tmp_min = min(tmp_min, current_min);
  }

  cout << tmp_min << endl;
}