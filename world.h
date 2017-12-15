/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Serves as a header file for world.cpp, implementing human.h and zombie.h
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
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
        //methods
          void progressDay();
          bool humansDed();
          void turnHuman(human&);
          void moveH(human&);
          void moveZ(zombie&);
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
