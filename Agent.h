#ifndef Agent_H
#define Agent_H

#include "Pazaak.h"

class Agent {
public:
  virtual ~Agent() {}
  virtual void turn(Pazaak& currentGame) = 0;
};

#endif
