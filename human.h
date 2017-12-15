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
        //constructors/de-constructor
          human();
          human(const human&);
          ~human();
        //getters/setters
          char getType() const;
          int getRow() const;
          int getCol() const;
          bool getMoved() const;
          void setType(char);
          void setRow(int);
          void setCol(int);
          void setMoved(bool);
        //methods
          void print();
          int checkMove();
          bool equals(human&);

      private:
        char type;
        int row;
        int col;
        bool moved;
        int genMove();
};

#endif
