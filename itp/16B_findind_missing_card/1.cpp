#include <cstdio>
#define RANK_SIZE 13
#define TRUMP_SIZE 52

char num_to_mark_array[] = {'S', 'H', 'C', 'D'};

char num_to_mark(int num) {
  return num_to_mark_array[num];
}

int mark_to_num(int mark) {
  for(int i = 0; i < sizeof(num_to_mark_array); i++) {
    if(num_to_mark_array[i] == mark) {
      return i;
    }
  }

  return -1;
}

struct Card {
  char mark;
  int rank;
};

int card_to_index(Card card) {
  return  mark_to_num(card.mark) * RANK_SIZE + (card.rank - 1);
}

Card index_to_card(int index) {
  Card card;
  card.mark = num_to_mark(index / RANK_SIZE);
  card.rank = index % RANK_SIZE + 1;
  return card;
}

// markは４種類しかないので、それぞれの配列に分けても良いかもしれない。
// 今回はサイクルのサイズをrank_sizeにして４つのmarkを１つの配列にした。
// 0オリジンの場合indexの数値と同じ数だけ左に要素がある。indexが0の時は左に0個、indexが13の時は左に13個要素がある。


int main() {
  int having_size;
  bool is_having_trump[TRUMP_SIZE] = {false};

  scanf("%d%*c", &having_size);
  for(int i = 0; i < having_size; i++) {
    Card card;
    scanf("%c %d%*c", &card.mark, &card.rank);

    is_having_trump[card_to_index(card)] = true;
  }

  for(int i = 0; i < TRUMP_SIZE; i++) {
    if(!is_having_trump[i]) {
      Card card = index_to_card(i);
      printf("%c %d\n", card.mark, card.rank);
    }
  }
}
