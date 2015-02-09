#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
#include <list>


class Player : public Agent {
  
private:
  
  Deck sideDeck;
  std::list<Card> hand;  // this might be better as a simple array
  
public:
  
  Player(const Deck& newDeck);
  virtual ~Player() {}
  virtual void turn(Pazaak& currentGame);
  void drawHand();
  
};
#endif


