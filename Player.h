#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"

cass Player : public Agent {
private:
  Deck sideDeck;
  Card myHand[5];
public:
  virtual PLayer(const Deck& newDeck);
  virtual ~Player() {}
  virtual void turn(Pazaak& currentGame);
};
#endif
