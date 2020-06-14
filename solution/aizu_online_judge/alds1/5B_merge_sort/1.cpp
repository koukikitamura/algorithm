#include <iostream>
#include <vector>

using namespace std;
const int max_value = 1'000'000'000 + 1;
int comparision_times = 0;

void merge(vector<int>& sequence, int top_index, int middle_index, int tail_index) {
  vector<int> first_half, second_half;
  first_half.resize((middle_index - top_index) + 1);
  second_half.resize((tail_index - middle_index) + 1);

  // Copy to tmp
  for(int i = 0; i < (middle_index - top_index); i++) {
    first_half[i] = sequence[top_index + i];
  }
  for(int i = 0; i < (tail_index - middle_index); i++) {
    second_half[i] = sequence[middle_index + i];
  }
  // Set sentinel
  first_half[first_half.size() - 1] = max_value;
  second_half[second_half.size() - 1] = max_value;

  int first_half_poped_index = 0;
  int second_half_poped_index = 0;
  for(int i = 0; i < tail_index - top_index; i++) {
    if(first_half[first_half_poped_index] < second_half[second_half_poped_index]) {
      sequence[top_index + i] = first_half[first_half_poped_index++];
    } else {
      sequence[top_index + i] = second_half[second_half_poped_index++];
    }
    comparision_times++;
  }
}

void merge_sort(vector<int>& sequence,  int top_index, int tail_index) {
  if(tail_index - top_index <= 1)  {
    return;
  }

  int middle_index = (top_index + tail_index) / 2;

  merge_sort(sequence, top_index, middle_index);
  merge_sort(sequence, middle_index, tail_index);

  merge(sequence, top_index, middle_index, tail_index);
}

int main() {
  int sequence_num;
  vector<int> sequence;

  // Init
  comparision_times = 0;
  cin >> sequence_num;

  sequence.resize(sequence_num);
  for(int i = 0; i < sequence_num; i++) {
    cin >> sequence[i];
  }

  // Do merge sort
  merge_sort(sequence, 0, sequence.size());

  // Output
  for(int i = 0; i < sequence_num; i++) {
    cout << sequence[i];
    if(i != sequence_num - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  cout << comparision_times << endl;
}
