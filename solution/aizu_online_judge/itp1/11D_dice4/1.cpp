#include <iostream>
#include <array>
#include <vector>

using namespace std;
using InnerDice = array<int, 6>;

class Dice {

  public:
    int top, bottom, left, right, front, back;

    void roll_east() {
      int before_right = right;

      right = top;
      top = left;
      left = bottom;
      bottom = before_right;
    }

    void roll_west() {
      int before_left = left;

      left = top;
      top = right;
      right = bottom;
      bottom = before_left;
    }

    void roll_north() {
      int before_back = back;

      back = top;
      top = front;
      front = bottom;
      bottom = before_back;
    }

    void rotate_clockwise() {
      int before_back = back;

      back = left;
      left = front;
      front = right;
      right = before_back;
    }

    // return ok or not
    bool roll(int afterTop, int afterFront) {
      if(afterTop == left) {
        roll_east();
      } else if(afterTop == right) {
        roll_west();
      }

      int try_count = 0;
      while(top != afterTop && try_count <= 3)  {
        roll_north();
        try_count++;
      }
      if(try_count > 3) {
        return false;
      }

      try_count = 0;
      while(front != afterFront && try_count <= 3) {
        rotate_clockwise();
        try_count++;
      };
      if(try_count > 3) {
        return false;
      }

      return true;
    }

    bool isSame(Dice other) {
      bool success = other.roll(top, front);
      if(!success) {
        return false;
      }

      return other.right == right &&
             other.left == left &&
             other.bottom == bottom &&
             other.back == back;
    }
};

int main() {
  int dice_num;
  vector<Dice> dices;

  cin >> dice_num;

  dices.resize(dice_num);

  for(int i = 0; i < dice_num; i++) {
    Dice current_dice;

    for(int i = 1; i <= 6; i++) {
      int face_label;
      cin >> face_label;

      switch (i) {
        case 1:
          current_dice.top = face_label;
          break;
        case 2:
          current_dice.front = face_label;
          break;
        case 3:
          current_dice.right = face_label;
          break;
        case 4:
          current_dice.left = face_label;
          break;
        case 5:
          current_dice.back = face_label;
          break;
        case 6:
          current_dice.bottom = face_label;
          break;
        default:
          return 1;
      }
    }

    dices[i] = current_dice;
  }


  // 全ての組み合わせを調べる
  bool isAllDifferent = true;
  for(int i = 0; i < dices.size() - 1; i++) {
    for(int j = i + 1; j < dices.size(); j++) {
      bool isSame = dices[i].isSame(dices[j]);

      if(isSame) {
        isAllDifferent = false;
        break;
      }
    }
  }

  if(isAllDifferent) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
