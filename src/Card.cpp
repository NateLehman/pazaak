#include "Card.h"



Card::Card():value(4), color("BLUE") {}

Card::Card(const int& _value, const std::string& _color, void (*f)(std::list<Card>*, int*, Card&)):value(_value),
									   color(_color),
									   playCard(f) {
  
}
