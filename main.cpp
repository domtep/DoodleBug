#include "sim.h"
#include "critter.h"
#include "ant.h"
#include "doodlebug.h"
#include <string>
#include <iostream>

int main(){
  std::string input ="";
  sim MainSim;
  MainSim.setSim();
  MainSim.print();
  while (input != "quit"){
    std::getline(std::cin, input);
    MainSim.nextStep();
    MainSim.print();
  }
  return 0;
}
