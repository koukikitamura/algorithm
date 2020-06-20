#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int infinity = numeric_limits<int>::max();

// l x mの行列とm x nの行列の行列の積を求めるには(l x m x n)回のスカラーの積を求める必要がある。

int main() {
  int matrix_num;
  vector<int> column_num_list;

  cin >> matrix_num;
  column_num_list.resize(matrix_num + 1);

  for(int i = 0; i < matrix_num; i++) {
    int row_num, column_num;
    cin >> row_num >> column_num;

    if(i == 0) {
      column_num_list[i] = row_num;
    }

    column_num_list[i + 1] = column_num;
  }

  // numberがi以上j以下の行列の積のスカラー積の回数(cost)はcosts[i][j]に格納する
  vector<vector<int>> costs(matrix_num + 1, vector<int>(matrix_num + 1, 0));

  // Init
  for(int i = 1; i <= matrix_num; i++) {
    costs[i][i] = 0;
  }

  for(int range = 2; range <= matrix_num; range++) {
    for(int first_label = 1; first_label <= matrix_num - range + 1; first_label++) {
      int last_label = first_label + range - 1;

      int min_cost = infinity;
      for(int left_last_label = first_label; left_last_label < last_label; left_last_label++) {
        int until_cost = costs[first_label][left_last_label] + costs[left_last_label + 1][last_label];
        int current_cost = column_num_list[first_label - 1] * column_num_list[left_last_label] * column_num_list[last_label];

        min_cost = min(until_cost + current_cost, min_cost);
      }

      costs[first_label][last_label] = min_cost;
    }
  }

  cout << costs[1][matrix_num] << endl;
}
