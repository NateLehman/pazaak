#include "Player.h"

Player::Player(const Deck& newDeck):sideDeck(newDeck) {
  
}

void Player::turn(Pazaak& currentGame) {
  if ((currentGame.getMyStandPtr(*this) != nullptr) && !*currentGame.getMyStandPtr(*this)) {
    currentGame.placeCard(currentGame.tableDeck.drawCard(), *this);
    // choose a card to place
    // choose to stand

    std::cout << "Player " << (currentGame.pNum(*this) + 1) << ":" << std::endl;
    std::cout << "Hand: " + handText() << std::endl;
    std::cout << "Choose card (-1 is no card): ";
    int cardChoice;
    std::cin >> cardChoice;
    if (cardChoice >= 0 && cardChoice < hand.size()) {
      currentGame.placeCard(hand[cardChoice], *this);
    }
    std::cout << "Stand? (Y/N)";
    std::string choice;
    std::cin >> choice;
    *currentGame.getMyStandPtr(*this) = (choice.at(0) == 'Y' || choice.at(0) == 'y');
  }
  currentGame.endTurn(*this);
}

void Player::drawHand() {

  while (!hand.empty()) {
    sideDeck.addCard(hand.back());
    hand.pop_back();
  }

  sideDeck.shuffle();

  for (size_t i = 0; i < 4; i++) {
    hand.push_back(sideDeck.drawCard());
  }
}

std::string Player::handText() {
  std::string myHand = "";
  char numstr[21];
  for (size_t i = 0; i < hand.size(); i++) {
    sprintf(numstr, "%lu", i);
    myHand = myHand + "|" + numstr + " " + hand[i].cardText() + "|";
  }
  return myHand;
}
