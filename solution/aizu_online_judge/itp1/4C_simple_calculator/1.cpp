#include<cstdio>

int main() {
  int operand1, operand2;
  char op;
  int result;
  bool end_input = false;

  while(!end_input) {
    scanf("%d %c %d%*c", &operand1, &op, &operand2);

    switch(op) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      case '?':
        end_input = true;
    };

    if(!end_input) {
      printf("%d\n", result);
    }
  }
}
