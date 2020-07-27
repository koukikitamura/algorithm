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
  int n;
  cin >> n;

  int left = n;
  int sum = 0;
  while(left > 0) {
    sum += left % 10;
    left /= 10;
  }

  if(n % sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}