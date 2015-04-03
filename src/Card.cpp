#include "Card.h"



Card::Card():value(4), color("BLUE") {}

Card::Card(const int& _value, const std::string& _color, void (*f)(std::vector<Card>*, int*, Card&)):value(_value),
									   color(_color),
									   playCard(f) {
  
}

std::string Card::cardText() {
  char numstr[21];
  sprintf(numstr, "%d", value);
  return color + " " + numstr;
}

