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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  // 水の有効な組み合わせ
  // 砂糖が0gのときは純水を出力
  int water_mass_ans = 100 * a;
  int sugar_mass_ans = 0;
  double tmp_max_concentration = 0;

  // 水の組み合わせ
  for(int ai = 0; ai * a * 100 <= f; ai++) {
    for(int bi = 0; ai * a * 100 + bi * b * 100 <= f; bi++) {
      int water_mass = (ai * a * 100 + bi * b * 100);
      int left_mass = f - water_mass;
      int can_max_suggar_max = water_mass / 100 * e;

      // 砂糖の組み合わせ
      for(int ci = 0; ci * c <= left_mass; ci++)  {
        for(int di = 0; ci * c + di * d <= left_mass; di++) {
          int sugar_mass = ci * c + di * d ;

          if(sugar_mass <= can_max_suggar_max) {
            if((water_mass + sugar_mass) == 0) {
              continue;
            }

            double concentration = 100 * sugar_mass / (double)(water_mass + sugar_mass);

            if(concentration > tmp_max_concentration) {
              water_mass_ans = water_mass;
              sugar_mass_ans = sugar_mass;
              tmp_max_concentration = concentration;
            }
          }
        }
      }
    }
  }

  cout << water_mass_ans + sugar_mass_ans << " " << sugar_mass_ans << endl;
}