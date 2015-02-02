#include <string>
#include <iostream>
#include <stddef.h>
#include <cstdlib>
#include <stdexcept>

#include "Deck.h"
#include "Card.h"
#include "Pazaak.h"
#include "Agent.h"
#include "Player.h"
#include "Dealer.h"


int main() {
  Card myCard1(4, "GREEN");
  Card myCard2(5, "BLUE");
  Deck myDeck;

  myDeck.addCard(myCard1);
  myDeck.addCard(myCard2);

  Card drawnCard = myDeck.drawCard();

  
  std::cout << "myCard2\t\t" << myCard2.getColor() << std::endl;
  std::cout << "drawnCard\t" << drawnCard.getColor() << std::endl;
  std::cout << "maybeGreenCard\t" << (myDeck.drawCard()).getColor() << std::endl;
  
  return 0;
}
