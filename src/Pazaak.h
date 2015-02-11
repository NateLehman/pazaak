#ifndef PAZAAK_H
#define PAZAAK_H

#include "Card.h"
#include <vector>

class Pazaak;

#include "Agent.h"
#include "Player.h"
#include "Dealer.h"

class Pazaak {

private:

  Player* p1;
  Player* p2;
  Dealer* dealer;
  std::vector<Card> p1Table;
  std::vector<Card> p2Table;
  int p1Sum;
  int p2Sum;
  size_t p1Rounds;
  size_t p2Rounds;
  bool gameFinished;
  bool p1Stand;
  bool p2Stand;

public:

  Deck tableDeck;
  
  Pazaak(Dealer* _dealer, Player* _p1, Player* _p2);

  void playGame();

  void placeCard(Card card, const Player& cPlayer);

  void endTurn(const Player& cPlayer);

  void endRound();
  
  // should return different sums depending on the player
  int* getSumPtr(const Player& cPlayer);

  std::vector<Card>* getTablePtr(const Player& cPlayer);

  int pNum(const Player& cPlayer);

  bool* getMyStandPtr(const Player& cPlayer);

  bool getOppStand(const Player& cPlayer);
};

#endif

