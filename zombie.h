/*******************************************************************************
 * zombie class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstdlib>
#include "human.h"

class zombie : public human
{
      public:
        //constructors/deconstructor
          zombie();
          zombie(human&)
          ~zombie();

};

#endif
