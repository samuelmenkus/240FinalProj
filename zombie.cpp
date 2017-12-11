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
zombie::zombie() : human () {
  type = 'Z';
}

zombie::zombie(human &oldHuman) : human(human &oldHuman) {
  type = 'Z';
}

zombie::~zombie() {

}

//methods

void zombie::print() {
  cout << getType();
}
