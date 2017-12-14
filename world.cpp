/*******************************************************************************
 * world class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "world.h"

using namespace std;

//constructors/deconstructor
world::world() {

}

world::~world() {

}

//getters/setters
int world::getDay() {
  return day;
}

 //methods
void world::turnHuman(human& oldHuman) {
  zombie(oldHuman);
}

void world::move(human& current) {
  if (current.checkMove() == 4) {
    return;
  }
  else {

  }
}

void world::progressDay() {
  //TODO: Add way for zombies and humans to move in this method
  for(int i = 0; i < grid.size(); i++) {
    
  }
  day++;
}

void world::printGrid() {
  cout << "World at Day " << getDay() << endl;
  cout << "+---+---+---+---+---+---+---+---+" << endl;
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < 8; j++) {
      cout << "| ";
      for(int k = 0; k < 8; k++) {
        cout << grid.at(i) << " | ";
      }
      cout << endl;
      cout << "+---+---+---+---+---+---+---+---+" << endl;
    }
  }
}
