/*******************************************************************************
 * world class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <cstdlib>
#include "human.h"
#include "zombie.h"

using namespace std;

class world
{
      public:
        //constructors/deconstructor
          world();
          ~world();
        //getters/setters
          int getDay();
          void progressDay();
        //methods
          void turnHuman(human&);
          void move();
          void printGrid();
      private:
        vector<human> *grid;
        int day;
};

#endif
