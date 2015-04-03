#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

struct Card {
  
  int value;
  std::string color;
  Card();
  Card(const int& _value, const std::string& _color, void (*f)(std::vector<Card>*, int*, Card&));
  std::string cardText();
  void (*playCard)(std::vector<Card>*, int*, Card&);  // Governs the properties of different cards.
  
};
#endif
