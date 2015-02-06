#include "Player.h"

Player::Player(const Deck& newDeck):sideDeck(newDeck) {
  
}

void Player::turn(Pazaak* currentGame) {
  currentGame->placeCard(currentGame->tableDeck.drawCard(), *this);
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
