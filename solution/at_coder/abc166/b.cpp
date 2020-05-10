#include<iostream>
#include<map>

using namespace std;

// お菓子を持っていないAの数を出力

int main() {
  int passenger_num;
  int sweets_num;
  map<int, bool> is_having_sweets_passenger;

  cin >> passenger_num >> sweets_num;

  // init
  for(int i = 1; i <= passenger_num; i++) {
    is_having_sweets_passenger[i] = false;
  }

  for(int i = 0; i < sweets_num; i++) {
    int victimus_with_swetts_num;
    cin >> victimus_with_swetts_num;

    for(int j = 0; j < victimus_with_swetts_num; j++) {
      int victim_label;
      cin >> victim_label;
      is_having_sweets_passenger[victim_label] = true;
    }
  }

  int victimus_num = 0;
  for(int i = 1; i <= passenger_num; i++) {
    if(!is_having_sweets_passenger[i]) {
      victimus_num++;
    }
  }

  cout << victimus_num << endl;

  return 0;
}
