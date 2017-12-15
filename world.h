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
#include <vector>
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
          bool humansDed(); 
          //methods
          void turnHuman(human&);
          void move(human&);
          void printGrid();

      private:
        int intNumHumans;
        int intNumZombies;
        std::vector<human> humans;
        std::vector<zombie> zombies;
        char grid[8][8];
        int day;
};

#endif
