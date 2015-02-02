#include "Deck.h"

Deck::Deck() {}

Card Deck::drawCard() {
  Card drawnCard = cardStack.top();
  cardStack.pop();
  return drawnCard;
}

void Deck::addCard(Card newCard) {
  cardStack.push(newCard);
}
