#include "sim.h"
#include "critter.h"
#include "ant.h"
#include "doodlebug.h"
#include <string>
#include <iostream>
#include <stdlib.h>

sim::sim(){
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      simulation[i][j] = nullptr;
    }
  }
}

void sim::setSim(){
  srand (time(NULL));
  int counter = 0;
  int i,j;
  while (counter < 5){
    i = rand() % 20;
    j = rand() % 20;
    if(simulation[i][j] == nullptr){
      simulation[i][j] = new doodlebug(i,j,this);
      counter++;
    }

  }
  counter = 0;
  while (counter < 100){
    i = rand() % 20;
    j = rand() % 20;
    if(simulation[i][j] == nullptr){
      simulation[i][j] = new ant(i,j,this);
      counter++;
    }
  }
}

void sim::print(){
  int ants = 0;
  int bug = 0;
  for (int i = 0; i < 20; i++){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout<< "|";
    for (int j = 0; j < 20; j++){
      if(simulation[i][j] != nullptr){
        std::cout<< simulation[i][j]->getSymbol() + "|";
        if(simulation[i][j]->getSymbol() == "X"){
          bug++;
        }else{
          ants++;
        }
      }else{
        std::cout << " |";
      }
    }
    std::cout<< std::endl;
  }
  std::cout << "-----------------------------------------" << std::endl;
  std::cout<< std::endl;
  std::cout<< bug << " " << ants << std::endl;
  std::cout<< std::endl;
}

void sim::nextStep(){
  moveCritter("X");

  moveCritter("O");
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      if(simulation[i][j] != nullptr){
          simulation[i][j]->hasMoved = false;
          simulation[i][j]->breed();
      }
    }
  }
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      if(simulation[i][j] != nullptr && simulation[i][j]->getSymbol() == "X"){
        if(simulation[i][j]->starve()){
          delete simulation[i][j];
          simulation[i][j] = nullptr;
        }
      }
    }
  }
}

void sim::moveCritter(std::string in){
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      if(simulation[i][j] != nullptr)
      if((simulation[i][j]->getSymbol()) == in && !(simulation[i][j]->hasMoved)){
          simulation[i][j]->move();
      }
    }
  }
}

sim::~sim(){
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 20; j++){
      delete simulation[i][j];
    }
  }
}
