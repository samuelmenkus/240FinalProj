/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Serves as a header file for human.cpp
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
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
