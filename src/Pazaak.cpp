#include "Pazaak.h"
#include <queue>
#include <vector>
#include <iostream>

Pazaak::Pazaak(Dealer* _dealer, Player* _p1, Player* _p2):dealer(_dealer),
							  p1(_p1),
							  p2(_p2) {
  p1Rounds = 0;
  p2Rounds = 0;
  p1Stand = 0;
  p2Stand = 0;
}


void Pazaak::playGame() {

  // players draw from their sidedecks
  p1->drawHand();
  p2->drawHand();

  // creates a queue for turn taking
  std::queue<Agent*> turnQueue;
  turnQueue.push(dealer);
  turnQueue.push(p1);
  turnQueue.push(p2);

  while (!gameFinished) {
    (turnQueue.front())->turn(*this);
    turnQueue.push(turnQueue.front());
    turnQueue.pop();
  }

  if (p1Rounds == 3) {
    std::cout << "Player 1 wins!" << std::endl;
  } else if (p2Rounds == 3) {
    std::cout << "Player 2 wins!" << std::endl;
  }
}

int* Pazaak::getSumPtr(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return &p1Sum;
  } else if (&cPlayer == p2) {
    return &p2Sum;
  } else {
    return nullptr;
  }
}

std::vector<Card>* Pazaak::getTablePtr(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return &p1Table;
  } else if (&cPlayer == p2) {
    return &p2Table;
  } else {
    return nullptr;
  }
}

void Pazaak::placeCard(Card card, const Player& cPlayer) {
  if (pNum(cPlayer) != -1) {
    card.playCard(getTablePtr(cPlayer), getSumPtr(cPlayer), card);
  }

  if (pNum(cPlayer) == 0) {
    std::cout << "player 1 played " << card.value << std::endl;
  } else {
    std::cout << "player 2 played " << card.value << std::endl;
  }

  std::cout << "Player 1 sum: " << p1Sum << std::endl;
  std::cout << "Player 2 sum: " << p2Sum << std::endl;
}

// this works, i think, but it's really, really shitty
void Pazaak::endTurn(const Player& cPlayer) {
  if (pNum(cPlayer) != -1) {
    if (*getSumPtr(cPlayer) == 20) {
      *getMyStandPtr(cPlayer) = true;
    }
    if (p1Stand && p2Stand && p1Sum <= 20 && p2Sum <= 20) {
      if (p1Sum != p2Sum) {
        if (p1Sum > p2Sum) {
          p1Rounds++;
        } else {
	  p2Rounds++;
	}
      }
      endRound();
    } else if (p1Sum > 20 || p2Sum > 20) {
      if (p1Sum > p2Sum) {
	p2Rounds++;
      } else {
	p1Rounds++;
      }
      endRound();
    }
  }
}

void Pazaak::endRound() {

  std::cout << "End of Round" << std::endl;
  std::cout << "Player 1 rounds: " << p1Rounds << std::endl;
  std::cout << "Player 2 rounds: " << p2Rounds << std::endl;
  
  p1Table.clear();
  p2Table.clear();
  p1Sum = 0;
  p2Sum = 0;
  p1Stand = 0;
  p2Stand = 0;
  gameFinished = (p1Rounds == 3 || p2Rounds == 3);
}

int Pazaak::pNum(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return 0;
  } else if (&cPlayer == p2) {
    return 1;
  } else {
    return -1;
  }
}

bool* Pazaak::getMyStandPtr(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return &p1Stand;
  } else if (&cPlayer == p2) {
    return &p2Stand;
  } else {
    return nullptr;
  }
}

bool Pazaak::getOppStand(const Player& cPlayer) {
  if (&cPlayer == p1) {
    return p2Stand;
  } else if (&cPlayer == p2) {
    return p1Stand;
  } else {
    return false;
  }
}
