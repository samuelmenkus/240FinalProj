/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Implements human.h, world.h, and zombie.h
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
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
