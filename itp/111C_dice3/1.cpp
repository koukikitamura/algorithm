#include<iostream>
#include<map>
#include<array>

using DiceLabel = std::map<int, int>;

class Dice {
  public:
    Dice(DiceLabel dice_arg) {
      dice = dice_arg;
    }

    int top() {
      return dice[top_index];
    }

    int front() {
      return dice[front_index];
    }

    int left() {
      return dice[left_index];
    }

    int right() {
      return dice[right_index];
    }

    void roll_east() {
      int before_right = dice[right_index];

      dice[right_index] = dice[top_index];
      dice[top_index] = dice[left_index];
      dice[left_index] = dice[bottom_index];
      dice[bottom_index] = before_right;
    }

    void roll_west() {
      int before_left = dice[left_index];

      dice[left_index] = dice[top_index];
      dice[top_index] = dice[right_index];
      dice[right_index] = dice[bottom_index];
      dice[bottom_index] = before_left;
    }

    void roll_north() {
      int before_back = dice[back_index];

      dice[back_index] = dice[top_index];
      dice[top_index] = dice[front_index];
      dice[front_index] = dice[bottom_index];
      dice[bottom_index] = before_back;
    }

    void rotate_clockwise() {
      int before_back = dice[back_index];

      dice[back_index] = dice[left_index];
      dice[left_index] = dice[front_index];
      dice[front_index] = dice[right_index];
      dice[right_index] = before_back;
    }

    void roll(int afterTop, int afterFront) {
      if(afterTop == left()) {
        roll_east();
      }
      if(afterTop == right()) {
        roll_west();
      }
      while(!(top() == afterTop)) {
        roll_north();
      }
      while(!(front() == afterFront)) {
        rotate_clockwise();
      }
    }

  private:
    const int top_index = 1;
    const int right_index = 3;
    const int bottom_index = 6;
    const int left_index = 4;
    const int front_index = 2;
    const int back_index = 5;
    DiceLabel dice;
};


const int DiceNum = 2;
const int DiceFaceNum = 6;

int main() {
  DiceLabel inner_dice1, inner_dice2;

  for(int i = 1; i <= DiceFaceNum; i++) {
    std::cin >> inner_dice1[i];
  }
    for(int i = 1; i <= DiceFaceNum; i++) {
    std::cin >> inner_dice2[i];
  }

  Dice dice1(inner_dice1), dice2(inner_dice2);

  dice2.roll(dice1.top(), dice1.front());

  std::string result;
  if(dice1.right() == dice2.right()) {
    result = "Yes";
  } else {
    result = "No";
  }

  std::cout << result << std::endl;
}
