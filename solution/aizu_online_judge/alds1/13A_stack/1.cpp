#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MAX_OPERANTD 1000000

int operand_count;
int operands[MAX_OPERANTD];

// log10(1) => 0
// log10(5) => 0.698970...
// log10(10) => 1
// log10(15) => 1.1769...
// log10(99) => 1.99653...
// log10(100) => 2

// 文字列と数値を連続でinputから受け取る場合は、文字列で受け取って、<cmath>atoiで文字列を数値に変換する。
// char expression[n];
// scanf("%s", expression);

void push(int num) {
  operands[operand_count] = num;
  operand_count++;
}

int pop() {
  int poped;
  poped = operands[operand_count - 1];
  operand_count--;
  return poped;
}

int main() {
  int operand_max_digit;
  operand_max_digit = log10(MAX_OPERANTD) + 1;
  char expression[operand_max_digit];
  int left_operand, right_operand;

  while(true) {
    if(scanf("%s", expression) == EOF) {
      break;
    }

    switch(expression[0]) {
      case '+':
        right_operand = pop();
        left_operand = pop();
        push(left_operand + right_operand);
        break;
      case '-':
        right_operand = pop();
        left_operand = pop();
        push(left_operand - right_operand);
        break;
      case '*':
        right_operand = pop();
        left_operand = pop();
        push(left_operand * right_operand);
        break;
      default:
        push(atoi(expression));
      }
  }

  int result = pop();
  printf("%d\n", result);
}
