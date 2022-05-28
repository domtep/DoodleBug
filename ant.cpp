#include "critter.h"
#include "sim.h"
#include "ant.h"
#include <stdlib.h>
#include <vector>
#include<array>
#include<iostream>

ant::ant(int x, int y, sim *in){
  this->x = x;
  this->y = y;
  thisSim = in;
  this->symbol = "O";
  breedCounter = 0;
}

void ant::move(){
  breedCounter++;
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

void ant::breed(){
  if(breedCounter >= 3){
    int i = rand() % 4;
    int ini = i;
    do{
      if(i == 0 && inRang(x+1,y) && thisSim->simulation[x+1][y] == nullptr ){
        thisSim->simulation[x+1][y] = new ant(x+1,y,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 1 && inRang(x-1,y) && thisSim->simulation[x-1][y] == nullptr ){
        thisSim->simulation[x-1][y] = new ant(x-1,y,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 2 && inRang(x,y+1) && thisSim->simulation[x][y+1] == nullptr ){
        thisSim->simulation[x][y+1] = new ant(x,y+1,thisSim);
        breedCounter = 0;
        return;
      }
      if(i == 3 && inRang(x,y-1) && thisSim->simulation[x][y-1] == nullptr ){
        thisSim->simulation[x][y-1] = new ant(x,y-1,thisSim);
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
