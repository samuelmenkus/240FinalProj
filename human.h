/*******************************************************************************
 * human class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstdlib>

using namespace std;

class human
{
      public:
        //constructors/deconstructor
          human();
          human(human*);
          ~human();
        //getters/setters
          char getType();
          int getRow();
          int getCol();
          bool getMoved();
          void setType(char);
          void setRow(int);
          void setCol(int);
          void setMoved(bool);
        //methods
          void print();
          int checkMove();

      private:
        char type;
        int row;
        int col;
        bool moved;
        int genMove();
};

#endif
