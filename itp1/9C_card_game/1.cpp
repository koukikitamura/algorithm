#include <iostream>
#include <string>
using namespace std;

const int score_win = 3;
const int score_draw = 1;

const int judge_win_player1 = 1;
const int judge_draw = 0;
const int judge_win_player2 = -1;

// std::string::compareを使えば良い
int judge(string word1, string word2) {
  int min_word_size = min(word1.size(), word2.size());

  for(int i = 0; i < min_word_size; i++) {
    int lexicographical_diff = word2[i] - word1[i];

    if(lexicographical_diff < 0) {
      return judge_win_player1;
    }
    if (lexicographical_diff > 0) {
      return judge_win_player2;
    }
  }

  if(word1.size() > word2.size()) {
    return judge_win_player1;
  } else if (word1.size() < word2.size()) {
    return judge_win_player2;
  }

  return judge_draw;
}

int main() {
  int turn_num;
  string player1_word, player2_word;
  int player1_score = 0, player2_score = 0;

  cin >> turn_num;

  for(int i = 0; i < turn_num; i++) {
    cin >> player1_word >> player2_word;

    int result = judge(player1_word, player2_word);

    if(result == judge_win_player1) {
        player1_score += score_win;
    } else if(result == judge_draw)  {
      player1_score += score_draw;
      player2_score += score_draw;
    } else if(result == judge_win_player2) {
      player2_score += score_win;
    }
  }

  printf("%d %d\n", player1_score, player2_score);
}
