#ifndef CRITTER_H
#define CRITTER_H

#include "critter.h"
#include <string>
#include <vector>
#include <array>

class sim;

class critter{
protected:
  sim *thisSim;
  std::string symbol;
  int x;
  int y;
public:
  bool hasMoved = false;
  critter(){}
  bool inRang(int x, int y);
  std::string getSymbol();
  void kill();
  int getX();
  int getY();
  virtual void move() = 0;
  virtual void breed() = 0;
  virtual bool starve() = 0;
  std::vector<critter*> getSurrounding();
  std::vector<std::string> getEmptySquares();
  ~critter(){}
};

#endif
