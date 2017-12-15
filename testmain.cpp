/*******************************************************************************
 * test main file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "human.h"
#include "zombie.h"
#include "world.h"

using namespace std;

int main(int argc, char **argv) {
  world Nirn;
  Nirn.printGrid();
  while (!Nirn.humansDed()) {
    Nirn.progressDay();
  }

  return 0;
}
