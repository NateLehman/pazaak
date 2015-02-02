#include "Deck.h"
#include <time.h>

Deck::Deck():size(0) {
  srand((size_t) time(NULL));
}

Card Deck::drawCard() {
  Card drawnCard = cardStack.top();
  cardStack.pop();
  return drawnCard;
}

void Deck::addCard(Card newCard) {
  cardStack.push(newCard);
}

/**
I know this is a really bad shuffle function if you wanted completely random
shuffling. But its also closer to how people really shuffle cards. Honestly I'm
torn at the moment.

void Deck::shuffle() {
  if (this->numCards() >= 2) {
    Deck shuf1;
    Deck shuf2;
    while (this->numCards() >= 2) {
      shuf1.addCard(this->drawCard());
      shuf2.addCard(this->drawCard());
    }
    shuf1.addCard(this->drawCard());
    while (!shuf1.isEmpty() || !shuf2.isEmpty()) {
      if (shuf1.isEmpty()) {
	this->addCard(shuf2.drawCard());
      } else if (shuf2.isEmpty()) {
	this->addCard(shuf1.drawCard());
      } else {
	(rand()/RAND_MAX) ?
	  (this->addCard(shuf1.drawCard())) : (this->addCard(shuf2.drawCard()));
      }
    }
  }
}
**/

void Deck::shuffle() {
  if ((size_t deckSize = this->numCards()) >= 2) {
    Card DeckArr[deckSize];
    for (size_t i = 0; i < deckSize; i++) {
      size_t j = rand() % (i + 1);
      if (j != i) {
	DeckArr[i] = DeckArr[j];
      }
      DeckArr[j] = this-drawCard();
    }
    for (size_t i = 0; i < deckSize; i++) {
      this->addCard(DeckArr[i]);
    }
  }
}
