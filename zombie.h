/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Serves as a header file for zombie.cpp and implements human.h
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
 ******************************************************************************/
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstdlib>
#include "human.h"

class zombie : public human
{
      public:
        //constructors/de-constructor
          zombie();
          zombie(const zombie&);
          ~zombie();

};

#endif
