#include <iostream>
#include <vector>

using namespace std;

// bit全探索

vector<int> sequence;

bool constractable(int target) {
  int bit_digit = sequence.size();

  for(int i = 0; i < 1 << bit_digit; i++) {
    int sum = 0;

    for(int j = 0; j < bit_digit; j++) {
      if(i >> j & 1) {
        sum += sequence[j];

        if(sum > target) {
          break;
        }
      }
    }

    if(sum == target) {
      return true;
    }
  }

  return false;
}

int main() {
  int sequence_num;
  cin >> sequence_num;
  sequence.resize(sequence_num);

  for(int i = 0; i < sequence_num; i++) {
    cin >> sequence[i];
  }

  int query_num;
  cin >> query_num;
  for(int i = 0; i < query_num; i++) {
    int query;

    cin >> query;

    if(constractable(query)) {
      cout << "yes" << endl;
    }  else {
      cout << "no" << endl;
    }
  }
}