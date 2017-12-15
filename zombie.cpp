/*******************************************************************************
 * zombie class file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "zombie.h"

using namespace std;

//constructors/deconstructor
zombie::zombie() {
  setType('Z');
  setCol(0);
  setRow(0);
  setMoved(false);
}

zombie::zombie(const zombie &oldZombie) {
  setType('Z');
  setCol(oldZombie.getCol());
  setRow(oldZombie.getRow());
  setMoved(oldZombie.getMoved());
}

zombie::~zombie() {

}
