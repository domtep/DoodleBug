#include "critter.h"
#include "sim.h"
#include <string>
#include <vector>
#include <iostream>

std::string critter::getSymbol(){
  return symbol;
}

void critter::kill(){
  thisSim->simulation[x][y]= nullptr;
}

bool critter::inRang(int x, int y){
  if(x < 0 || x > 19 || y > 19 || y < 0 ){
    return false;
  }
  return true;
}

std::vector<critter*> critter::getSurrounding(){
  std::vector<critter*> output;
  if(inRang(x+1,y)){
    output.push_back(thisSim->simulation[x+1][y]);
  }
  if(inRang(x-1,y)){
    output.push_back(thisSim->simulation[x-1][y]);
  }
  if(inRang(x,y+1)){
    output.push_back(thisSim->simulation[x][y+1]);
  }
  if(inRang(x,y-1)){
    output.push_back(thisSim->simulation[x][y-1]);
  }
  return output;
}

std::vector<std::string> critter::getEmptySquares(){
  std::vector<std::string> output;
  if(inRang(x+1,y) && thisSim->simulation[x+1][y] == nullptr ){
    output.push_back("up");
  }
  if(inRang(x-1,y)&& thisSim->simulation[x-1][y] == nullptr){
    output.push_back("down");
  }
  if(inRang(x,y+1)&& thisSim->simulation[x][y+1] == nullptr){
    output.push_back("right");
  }
  if(inRang(x,y-1) && thisSim->simulation[x][y-1] == nullptr){
    output.push_back("left");
  }
  return output;
}

int critter::getX(){return x;}
int critter::getY(){return y;}
