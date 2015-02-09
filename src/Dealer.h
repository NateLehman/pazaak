#ifndef DEALER_H
#define DEALER_H

class Dealer;

#include "Pazaak.h"

class Dealer : public Agent {
private:
  
public:
  Dealer();
  virtual ~Dealer() {}
  virtual void turn(Pazaak& currentGame) {};
};
#endif
