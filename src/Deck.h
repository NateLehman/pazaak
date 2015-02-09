#ifndef DECK_H
#define DECK_H


#include "Card.h"
#include <stack>

class Deck {
private:
  std::stack<Card> cardStack;
  void print();
public:
  Deck();
  Card drawCard();
  void addCard(Card newCard);
  size_t numCards() {  return cardStack.size();  }
  bool isEmpty() {  return cardStack.empty();  }
  void shuffle();
};
#endif
