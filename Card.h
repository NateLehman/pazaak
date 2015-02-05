#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>

class Card {  // consider changing to struct
  
private:
  
  size_t value;
  std::string color;

public:
  
  Card();
  Card(const int& _value, const std::string& _color, int (*f)(std::list<Card>*, Card&));
  int getValue() {return value;};
  std::string getColor() {return color;};
  int (*playCard)(std::list<Card>*, Card&);  // this will eventually hold the properties of different cards.
};
#endif
