#include <iostream>
#include <string>
#include <algorithm>

// Time Exeeded Error

using namespace std;
const int MaxStringSize = 1000;

// Memo[n][m] は str1.sub(0, n) と str2.sub(0, m)のLCSをmemoする。
int MemoLCS[MaxStringSize + 1][MaxStringSize + 1];
int NullMemo = -1;

void init_memo() {
  for(int i = 0; i <= MaxStringSize; i++) {
    for(int j = 0; j <= MaxStringSize; j++) {
      if (i == 0 || j == 0) {
         MemoLCS[i][j] = 0;
      }
      MemoLCS[i][j] = NullMemo;
    }
  }
}

int calc_LCS(string str1, string str2) {
  if(MemoLCS[str1.size()][str2.size()] != NullMemo) {
    return MemoLCS[str1.size()][str2.size()];
  }

  if(str1.size() == 0 || str2.size() == 0) {
    return 0;
  }

  string sub_str1 = str1.substr(0, str1.size() - 1);
  string sub_str2 = str2.substr(0, str2.size() - 1);
  if(str1.back() == str2.back()) {
    return calc_LCS(sub_str1, sub_str2) + 1;
  }

  int lcs_choise1 = calc_LCS(str1, sub_str2);
  int lcs_choise2 = calc_LCS(sub_str1, str2);
  int lcs = max(lcs_choise1, lcs_choise2);

  MemoLCS[str1.size()][str2.size()] = lcs;
  return lcs;
}

int main() {
  int datasets_num;
  string str1;
  string str2;

  cin >> datasets_num;

  for(int i = 0; i < datasets_num; i++) {
    init_memo();
    cin >> str1 >> str2;

    cout << calc_LCS(str1, str2) << endl;
  }
}
