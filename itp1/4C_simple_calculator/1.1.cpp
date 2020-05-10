#include<cstdio>

int main() {
  int left_operand, right_operand;
  char op;
  int result;
  bool end_input = false;

  while(true) {
    scanf("%d %c %d%*c", &left_operand, &op, &right_operand);

    if(op == '?') {
      break;
    }

    switch(op) {
      case '+':
        result = left_operand + right_operand;
        break;
      case '-':
        result = left_operand - right_operand;
        break;
      case '*':
        result = left_operand * right_operand;
        break;
      case '/':
        result = left_operand / right_operand;
        break;
    };

    printf("%d\n", result);
  }
}
