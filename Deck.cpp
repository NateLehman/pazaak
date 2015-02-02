#include "Deck.h"
#include <time.h>
#include <cstdlib>

Deck::Deck(){
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

void Deck::shuffle() {
  size_t deckSize = this->numCards();
  if (deckSize >= 2) {
    Card *cardArr = new Card[deckSize];
    for (size_t i = 0; i < deckSize; i++) {
      size_t j = rand() % (i + 1);
      if (j != i) {
	cardArr[i] = cardArr[j];
      }
      cardArr[j] = this->drawCard();
    }
    for (size_t i = 0; i < deckSize; i++) {
      this->addCard(cardArr[i]);
    }
    delete [] cardArr;
  }
}
