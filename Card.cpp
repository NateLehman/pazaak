#include "Card.h"



Card::Card():value(4), color("BLUE") {}

Card::Card(const int& _value, const std::string& _color, int (*f)(std::list<Card>*, Card&)):value(_value),
									   color(_color),
									   playCard(f) {
  
}
