#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

vector<ll> sequence;

ll count_combination(ll condition) {
  ll combination_count = 0;
  ll range_sum = 0;
  int tail = 1;
  for(int head = 0; head < sequence.size(); head++) {
    while(range_sum + sequence[tail - 1] <= condition && tail <= sequence.size()) {
      range_sum += sequence[tail++ - 1];
    }
    combination_count += (tail - 1) - head;

    if(tail - head < 1) {
      tail++;
    }

    range_sum -= sequence[head];
  }

  return combination_count;
}

int main() {
  int sequence_num;
  int query_num;

  cin >> sequence_num >> query_num;
  sequence.resize(sequence_num);

  for(int i = 0; i < sequence_num; i++) {
    cin >> sequence[i];
  }

  for(int i = 0; i < query_num; i++) {
    ll sub_sum;
    cin >> sub_sum; // x

    ll combination_num = count_combination(sub_sum);
    cout << combination_num << endl;
  }
}