#ifndef DEALER_H
#define DEALER_H

#include "Pazaak.h"

class Dealer : public Agent {
private:
  
public:
  virtual ~Dealer() {}
  virtual void turn(Pazaak* currentGame);
};

#endif
