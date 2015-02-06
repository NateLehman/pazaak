#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>

struct Card {  // consider changing to struct
  
  size_t value;
  std::string color;
  Card();
  Card(const int& _value, const std::string& _color, void (*f)(std::list<Card>*, int*, Card&));
  int getValue() {return value;};
  std::string getColor() {return color;};
  void (*playCard)(std::list<Card>*, int*, Card&);  // Governs the properties of different cards.
};
#endif
