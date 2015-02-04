#ifndef PAZAAK_H
#define PAZAAK_H

class Pazaak {
private:
  Deck mainDeck;
  Card[9] p1Cards;
  Card[9] p2Cards;
  size_t p1Sum;
  size_t p2Sum;
  size_t p1Wins;
  size_t p2Wins;
public:
  void playGame();
};

#endif
