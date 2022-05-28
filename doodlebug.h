#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "critter.h"
#include "sim.h"
#include <vector>

class doodlebug: public critter{
private:
  int breedCounter = 0;
  int starveCounter =0;
public:
  doodlebug(int x, int y, sim *in);
  void move();
  void breed();
  bool starve();
  ~doodlebug(){}
};

#endif
