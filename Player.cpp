#include "Player.h"

Player::Player(const Deck& newDeck):sideDeck(newDeck) {
  
}

void Player::turn(Pazaak* currentGame) {
  placeCard(currentGame, currentGame->tableDeck.drawCard());
}

void Player::placeCard(Pazaak* currentGame, Card heldCard) {
  std::list<Card>* myTablePtr = currentGame->getTablePtr(*this);
  int* mySumPtr = currentGame->getSumPtr(*this);
  *mySumPtr += heldCard.playCard(myTablePtr, heldCard);
  myTablePtr->push_front(heldCard);
}

void Player::drawHand() {

  while (!hand.empty()) {
    sideDeck.addCard(hand.front());
    hand.pop_front();
  }

  sideDeck.shuffle();

  for (size_t i = 0; i < 4; i++) {
    hand.push_front(sideDeck.drawCard());
  }
}
