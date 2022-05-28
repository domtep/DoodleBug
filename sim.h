#ifndef SIM_H
#define SIM_H

#include "critter.h"
#include <string>

class sim{
  friend class critter;
  friend class ant;
  friend class doodlebug;
private:
  critter *simulation[20][20];
public:
  sim();
  void setSim();
  void print();
  void nextStep();
  void moveCritter(std::string in);
  ~sim();

};
#endif
