#include<iostream>
using namespace std;

string shuffle(string deck, int num) {
  string shuffled = "";

  shuffled += deck.substr(num, deck.size() - num);
  shuffled += deck.substr(0, num);

  return shuffled;
}

int main() {
  string deck;
  int shuffle_size;
  int shuffle_card_num;

  while(true) {
    cin >> deck;

    if(deck == "-") {
      break;
    }

    cin >> shuffle_size;

    string shuffled_deck = deck;
    for(int i = 0; i < shuffle_size; i++) {
      cin >> shuffle_card_num;

      shuffled_deck = shuffle(shuffled_deck, shuffle_card_num);
    }


    cout << shuffled_deck << endl;
  }
}
