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
  setType('Z');
}

zombie::zombie(human *oldHuman) : human(human *oldHuman) {
  setType('Z');
}

zombie::~zombie() {

}
