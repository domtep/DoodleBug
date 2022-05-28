#ifndef ANT_H
#define ANT_H

#include "critter.h"
#include "sim.h"

class ant: public critter{
private:
  int breedCounter = 0;
public:
  ant(int x, int y, sim *in);
  bool starve(){}
  void breed();
  void move();
  ~ant(){}
};

#endif
