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



int greenCard(std::list<Card>* tableCards, Card& me) {
  return me.getValue();
}


int main() {

  Deck p1Deck;
  Deck p2Deck;

  for (size_t i = 0; i < 10; i++) {
    Card newCard(i, "GREEN", &greenCard);
    p1Deck.addCard(newCard);
    p2Deck.addCard(newCard);
  }

  Player p1(p1Deck);
  Player p2(p2Deck);
  Dealer del;

  Pazaak game(&del, &p1, &p2);

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      Card newCard(i, "GREEN", &greenCard);
      game.tableDeck.addCard(newCard);
    }
  }

  game.tableDeck.shuffle();
  p1.drawHand();
  p1.placeCard(&game, game.tableDeck.drawCard());

  int* sum = game.getSumPtr(p1);

  std::cout << *sum << std::endl;
  
  return 0;
}
