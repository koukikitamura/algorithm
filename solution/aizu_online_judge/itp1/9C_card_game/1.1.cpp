#include <iostream>
#include <string>
using namespace std;

const int score_win = 3;
const int score_draw = 1;

int main() {
  int turn_num;
  string player1_word, player2_word;
  int player1_score = 0, player2_score = 0;

  cin >> turn_num;

  for(int i = 0; i < turn_num; i++) {
    cin >> player1_word >> player2_word;

    int result = player1_word.compare(player2_word);

    if(result == 0) {
      player1_score += score_draw;
      player2_score += score_draw;
    } else if(result > 0) {
      player1_score += score_win;
    } else {
      player2_score += score_win;
    }
  }

  printf("%d %d\n", player1_score, player2_score);
}
