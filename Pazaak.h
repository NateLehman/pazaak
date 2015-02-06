#ifndef PAZAAK_H
#define PAZAAK_H

#include "Card.h"
#include <list>

class Pazaak;

#include "Agent.h"
#include "Player.h"
#include "Dealer.h"

class Pazaak {

private:

  Player* p1;
  Player* p2;
  Dealer* dealer;
  std::list<Card> p1Table;
  std::list<Card> p2Table;
  int p1Sum;
  int p2Sum;
  size_t p1Rounds;
  size_t p2Rounds;
  bool gameFinished;

public:

  Deck tableDeck;
  
  Pazaak(Dealer* _dealer, Player* _p1, Player* _p2);

  void playGame();

  void placeCard(Card card, const Player& cPlayer);
  
  // should return different sums depending on the player
  int* getSumPtr(const Player& cPlayer);

  std::list<Card>* getTablePtr(const Player& cPlayer);
};

#endif
