#include <string>
#include <iostream>
#include <stddef.h>
#include <cstdlib>
#include <stdexcept>

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
#include "Agent.h"
#include "Player.h"
#include "Dealer.h"



void playGreenCard(std::list<Card>* tableCards, int* sum, Card& me) {
  *sum += me.value;
  tableCards->push_front(me);
}

int main() {

  Deck p1Deck;
  Deck p2Deck;

  for (size_t i = 0; i < 10; i++) {
    Card newCard(i, "GREEN", &playGreenCard);
    p1Deck.addCard(newCard);
    p2Deck.addCard(newCard);
  }

  Player p1(p1Deck);
  Player p2(p2Deck);
  Dealer del;

  Pazaak game(&del, &p1, &p2);

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      Card newCard(i, "RED", &playGreenCard);
      game.tableDeck.addCard(newCard);
    }
  }

  game.tableDeck.shuffle();
  p1.drawHand();

  game.placeCard(game.tableDeck.drawCard(), p1);

  int* sum = game.getSumPtr(p1);
  std::list<Card>* p1Table = game.getTablePtr(p1);

  std::cout << *sum << std::endl;
  std::cout << p1Table->front().value << std::endl;
  
  
  return 0;
}
