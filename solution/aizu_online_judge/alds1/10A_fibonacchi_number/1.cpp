#include <iostream>

using namespace std;

const int MaxNum = 44;
int FibonacchiMemo[MaxNum + 1];
const int NullMemo = -1;

int fibonacci(int n) {
  if(FibonacchiMemo[n] != NullMemo) {
    return FibonacchiMemo[n];
  }

  int output;
  if (n == 0 || n == 1) {
    output = 1;
  } else {
    output = fibonacci(n - 1) + fibonacci(n - 2);
  }

  FibonacchiMemo[n] = output;
  return output;
}

void init_memo() {
  for(int i = 0; i <= MaxNum; i++) {
    FibonacchiMemo[i] = NullMemo;
  }
}

int main() {
  int n;
  init_memo();

  cin >> n;

  cout << fibonacci(n) << endl;
}
