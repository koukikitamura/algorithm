#include <iostream>
#include <array>

using namespace std;

const int MaxObservatoryNum = 100000;
// const int MaxObservatoryNum = 100;
// 負けがない展望台を出力

int main() {
  int observatory_num;
  int road_num;
  array<int, MaxObservatoryNum + 1> observatory_height_list;
  array<bool, MaxObservatoryNum + 1> is_good_observatory_list;

  cin >> observatory_num >> road_num;

  // init
  for(int i = 1; i <= observatory_num; i++)  {
    is_good_observatory_list[i] = true;
  }

  for(int i = 1; i <= observatory_num; i++) {
    cin >> observatory_height_list[i];
  }

  for(int i = 0; i < road_num; i++) {
    int label1, label2;
    cin >> label1 >> label2;

    if (observatory_height_list[label1] == observatory_height_list[label2]) {
      is_good_observatory_list[label1] = false;
      is_good_observatory_list[label2] = false;
      continue;
    }

    if(observatory_height_list[label1] > observatory_height_list[label2]) {
      is_good_observatory_list[label2] = false;
    } else {
      is_good_observatory_list[label1] = false;
    }
  }


  int is_good_observatory_num = 0;
  for(int i = 1; i <= observatory_num; i++ ) {
    if(is_good_observatory_list[i]) {
      is_good_observatory_num++;
    }
  }

  cout << is_good_observatory_num << endl;
  return 0;
}
