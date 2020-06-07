#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
const int MaxStringSize = 1000;
const int NullMemo = -1;

int calc_LCS(string str1, string str2) {
  // Memo[n][m] は str1.sub(0, n) と str2.sub(0, m)のLCSをmemoする。
  int memoLCS[str1.size() + 1][str2.size() + 1];

  for(int i = 0; i <= str1.size(); i++) {
    memoLCS[i][0] = 0;
  }
  for(int i = 0; i <= str2.size(); i++) {
    memoLCS[0][i] = 0;
  }

  for(int i = 1; i <= str1.size(); i++) {
    for(int j = 1; j <= str2.size(); j++) {
      if(str1[i - 1] == str2[j - 1]) {
        memoLCS[i][j] = memoLCS[i - 1][j - 1] + 1;
      } else {
        memoLCS[i][j] = max(memoLCS[i][j - 1], memoLCS[i - 1][j]);
      }
    }
  }

  return memoLCS[str1.size()][str2.size()];
}

int main() {
  int datasets_num;
  string str1;
  string str2;

  cin >> datasets_num;

  for(int i = 0; i < datasets_num; i++) {
    cin >> str1 >> str2;

    cout << calc_LCS(str1, str2) << endl;
  }
}
