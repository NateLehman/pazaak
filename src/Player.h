#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
//#include <list>
#include <vector>
#include <string>
#include <iostream>

class Player : public Agent {
  
private:
  
  Deck sideDeck;
  std::vector<Card> hand;  // this might be better as a simple array
  
public:
  
  Player(const Deck& newDeck);
  virtual ~Player() {}
  virtual void turn(Pazaak& currentGame);
  void drawHand();
  std::string handText();
  
};
#endif


