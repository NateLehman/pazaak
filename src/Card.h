#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>

struct Card {
  
  int value;
  std::string color;
  Card();
  Card(const int& _value, const std::string& _color, void (*f)(std::list<Card>*, int*, Card&));
  void (*playCard)(std::list<Card>*, int*, Card&);  // Governs the properties of different cards.
  
};
#endif
