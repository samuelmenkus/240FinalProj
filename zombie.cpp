/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Implements zombie.h
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "zombie.h"

using namespace std;

//constructors/deconstructor
/*******************************************************************************
 * Function: Default constructor
 * Input: None
 * Output: None
 ******************************************************************************/
zombie::zombie() {
  setType('Z');
  setCol(0);
  setRow(0);
  setMoved(false);
}

/*******************************************************************************
 * Function: Copy constructor
 * Input: &zombie
 * Output: None
 ******************************************************************************/
zombie::zombie(const zombie &oldZombie) {
  setType('Z');
  setCol(oldZombie.getCol());
  setRow(oldZombie.getRow());
  setMoved(oldZombie.getMoved());
}

/*******************************************************************************
 * Function: De-constructor
 * Input: None
 * Output: None
 ******************************************************************************/
zombie::~zombie() {

}
