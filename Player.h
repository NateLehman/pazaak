#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
#include <list>


class Player : public Agent {
private:
  Deck sideDeck;
  std::list<Card> hand;
public:
  Player(const Deck& newDeck);
  virtual ~Player() {}
  virtual void turn(Pazaak& currentGame);
  virtual void drawHand();
  
};
#endif
