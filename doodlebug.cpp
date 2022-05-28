#include "critter.h"
#include "sim.h"
#include "doodlebug.h"
#include <string>
#include <stdlib.h>
#include <vector>
#include<iostream>
#include <array>

doodlebug::doodlebug(int x, int y, sim *in){
  this->x = x;
  this->y = y;
  thisSim = in;
  this->symbol = "X";
}


void doodlebug::move(){
  breedCounter++;
  std::vector<critter*> surrounding= getSurrounding();
  for(critter* in: surrounding){
    if(in != nullptr){
      if(in->getSymbol() == "O"){
        int tempx = in->getX();
        int tempy = in->getY();
        delete thisSim->simulation[tempx][tempy];
        thisSim->simulation[tempx][tempy] = this;
        thisSim->simulation[x][y] = nullptr;
        x = tempx;
        y = tempy;
        hasMoved = true;
        starveCounter = 0;
        return;
      }
    }
  }
  starveCounter++;
  std::vector<std::string> spaces = getEmptySquares();
  if(spaces.size() != 0){
    int i = rand() % spaces.size();
    if(spaces[i] == "up"){
      thisSim->simulation[x+1][y] = this;
      thisSim->simulation[x][y] = nullptr;
      x++;
      hasMoved = true;
      return;
    }else if(spaces[i] == "down"){
      thisSim->simulation[x-1][y] = this;
      thisSim->simulation[x][y] = nullptr;
      x--;
      hasMoved = true;
      return;
    }else if(spaces[i] == "right"){
      thisSim->simulation[x][y+1] = this;
      thisSim->simulation[x][y] = nullptr;
      y++;
      hasMoved = true;
      return;
    }else if(spaces[i] == "left"){
      thisSim->simulation[x][y-1] = this;
      thisSim->simulation[x][y] = nullptr;
      y--;
      hasMoved = true;
      return;
    }
  }
}

bool doodlebug::starve(){
  if(starveCounter >= 3){
    return true;
  }
  return false;
}

void doodlebug::breed(){
  if(breedCounter >= 8){
    int i = rand() % 4;
    int ini = i;
    do{
      if(i == 0 && inRang(x+1,y) && thisSim->simulation[x+1][y] == nullptr ){
        thisSim->simulation[x+1][y] = new doodlebug(x+1,y,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 1 && inRang(x-1,y) && thisSim->simulation[x-1][y] == nullptr ){
        thisSim->simulation[x-1][y] = new doodlebug(x-1,y,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 2 && inRang(x,y+1) && thisSim->simulation[x][y+1] == nullptr ){
        thisSim->simulation[x][y+1] = new doodlebug(x,y+1,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 3 && inRang(x,y-1) && thisSim->simulation[x][y-1] == nullptr ){
        thisSim->simulation[x][y-1] = new doodlebug(x,y-1,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 3){
        i = 0;
      }else{
        i++;
      }
    }while (i != ini);
  }
}
