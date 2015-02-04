#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
  size_t value;
  std::string color;
  void (*playCard)(Card[9], int);  // this will eventually hold the properties of different cards.
public:
  Card();
  Card(const int& _value, const std::string& _color);
  int getValue() {return value;};
  std::string getColor() {return color;};
};
#endif
