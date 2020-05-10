#include <string>
#include <iostream>
#define DICE_FACE_SIZE 6
using namespace std;

int main() {
  int dice[DICE_FACE_SIZE + 1];
  string commands;

  for(int i = 0; i < DICE_FACE_SIZE; i++) {
    cin >> dice[i + 1];
  }
  cin >> commands;

  int east_label = 3;
  int west_label = 4;
  int north_label = 5;
  int south_label = 2;
  int top_label = 1;
  int bottom_label = 6;

  for(int i = 0; i < commands.size(); i++) {
     double before_bottom_label;

    switch(commands[i]) {
      case 'N':
        before_bottom_label = 7 - top_label;

        bottom_label = north_label;
        north_label = top_label;
        top_label = south_label;
        south_label = before_bottom_label;

        break;
      case 'E':
        before_bottom_label = 7 - top_label;

        bottom_label = east_label;
        east_label = top_label;
        top_label = west_label;
        west_label = before_bottom_label;
        break;
      case 'S':
        before_bottom_label = 7 - top_label;

        bottom_label = south_label;
        south_label = top_label;
        top_label = north_label;
        north_label = before_bottom_label;
        break;
      case 'W':
        before_bottom_label = 7 - top_label;

        bottom_label = west_label;
        west_label = top_label;
        top_label = east_label;
        east_label = before_bottom_label;
        break;
    }
  }

  cout << dice[top_label] << endl;
}
