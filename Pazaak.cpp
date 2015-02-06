#include "Pazaak.h"
#include <queue>

Pazaak::Pazaak(Dealer* _dealer, Player* _p1, Player* _p2):dealer(_dealer),
							  p1(_p1),
							  p2(_p2) {
  p1Rounds = 0;
  p2Rounds = 0;
}

void Pazaak::playGame() {

  // players draw from their sidedecks
  p1->drawHand();
  p2->drawHand();

  // creates a queue for turn taking
  std::queue<Agent*> turnQueue;
  turnQueue.push(dealer);
  turnQueue.push(p1);
  turnQueue.push(p2);

  while (!gameFinished) {
    (turnQueue.front())->turn(this);
    turnQueue.push(turnQueue.front());
    turnQueue.pop();
  }
}

int* Pazaak::getSumPtr(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return &p1Sum;
  } else if (&cPlayer == p2) {
    return &p2Sum;
  } else {
    return nullptr;
  }
}

std::list<Card>* Pazaak::getTablePtr(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return &p1Table;
  } else if (&cPlayer == p2) {
    return &p2Table;
  } else {
    return nullptr;
  }
}

void Pazaak::placeCard(Card card, const Player& cPlayer) {
  card.playCard(getTablePtr(cPlayer), getSumPtr(cPlayer), card);  // add checks to see if they are nullptr
}
