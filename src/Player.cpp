#include "Player.h"

Player::Player(const Deck& newDeck):sideDeck(newDeck) {
  
}

void Player::turn(Pazaak& currentGame) {
  if ((currentGame.getMyStandPtr(*this) != nullptr) && !*currentGame.getMyStandPtr(*this)) {
    currentGame.placeCard(currentGame.tableDeck.drawCard(), *this);
    // choose a card to place
    // choose to stand
  }
  currentGame.endTurn(*this);
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
