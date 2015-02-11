#include <string>
#include <iostream>
#include <stddef.h>
#include <cstdlib>
#include <stdexcept>
#include <list>

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
#include "Agent.h"
#include "Player.h"
#include "Dealer.h"



void addingCard(std::vector<Card>* tableCards, int* sum, Card& me) {
  *sum += me.value;
  tableCards->push_back(me);
}

void doubleCard(std::vector<Card>* tableCards, int* sum, Card& me) {
  int* prevVal = &tableCards->front().value;
  *sum -= *prevVal;
  *prevVal *= 2;
  *sum += *prevVal;
  tableCards->push_back(me);
}

// the flipcard flips the sign of cards whose value are value and value*2 of the flipcard
void flipCard(std::vector<Card>* tableCards, int* sum, Card& me) {
  int newSum = 0;
  for (std::vector<Card>::iterator it = tableCards->begin(); it != tableCards->end(); it++) {
    if (it->value == me.value || it->value == me.value * 2) {
      it->value = -it->value;
    }
    newSum += it->value;
  }
  *sum = newSum;
  me.value = 0;
  tableCards->push_back(me);
}

int main() {

  Deck p1Deck;
  Deck p2Deck;

  for (size_t i = 0; i < 10; i++) {
    Card newCard(i, "RED", &addingCard);
    p1Deck.addCard(newCard);
    p2Deck.addCard(newCard);
  }

  Player p1(p1Deck);
  Player p2(p2Deck);
  Dealer del;

  Pazaak game(&del, &p1, &p2);

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      Card newCard(i + 1, "GREEN", &addingCard);
      game.tableDeck.addCard(newCard);
    }
  }

  game.tableDeck.shuffle();
  game.tableDeck.shuffle();

  game.playGame();
  
  return 0;
}
