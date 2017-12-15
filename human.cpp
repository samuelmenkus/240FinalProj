/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Implements human.h
 * Input: Varies
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "human.h"

using namespace std;

//constructors/deconstructor
/*******************************************************************************
 * Function: Default human constructor
 * Input: None
 * Output: None
 ******************************************************************************/
human::human() {
  type = 'H';
  row = 0;
  col = 0;
  moved = false;
}

/*******************************************************************************
 * Function: Copy constructor
 * Input: &human
 * Output: None
 ******************************************************************************/
human::human(const human &oldHuman) {
  type = oldHuman.getType();
  row = oldHuman.getRow();
  col = oldHuman.getCol();
  moved = false;
}

/*******************************************************************************
 * Function: De-constructor
 * Input: None
 * Output: None
 ******************************************************************************/
human::~human() {

}

//getters/setters
/*******************************************************************************
 * Function: Sets type
 * Input: Char representing type ('H' or 'Z')
 * Output: None
 ******************************************************************************/
void human::setType(char _type) {
  type = _type;
}

/*******************************************************************************
 * Function: returns the type
 * Input: None
 * Output: Char representing type ('H' or 'Z')
 ******************************************************************************/
char human::getType() const {
  return type;
}

/*******************************************************************************
 * Function: returns the row
 * Input: None
 * Output: int representing row
 ******************************************************************************/
int human::getRow() const {
  return row;
}

/*******************************************************************************
 * Function: Returns the current column of the human
 * Input: None
 * Output: int representing column
 ******************************************************************************/
int human::getCol() const {
  return col;
}

/*******************************************************************************
 * Function: Returns a bool representing whether the human has moved or not
 * Input: None
 * Output: bool representing movement having taken place
 ******************************************************************************/
bool human::getMoved() const {
  return moved;
}

/*******************************************************************************
 * Function: sets row
 * Input: int representing row
 * Output: None
 ******************************************************************************/
void human::setRow(int _row) {
  if (_row >= 0 && _row < 8) {
    row = _row;
  }
}

/*******************************************************************************
 * Function: Sets the current column of the human
 * Input: int representing column
 * Output: None
 ******************************************************************************/
void human::setCol(int _col) {
  if (_col >= 0 && _col < 8) {
    col = _col;
  }
}

/*******************************************************************************
 * Function: Sets whether or not the current human has moved
 * Input: bool representing movement having taken place
 * Output: None
 ******************************************************************************/
void human::setMoved(bool _moved) {
  moved = _moved;
}

//methods
/*******************************************************************************
 * Function: Prints information about the Human
 * Input: None
 * Output: information about the human
 ******************************************************************************/
void human::print() {
  cout << getType() << " at col " << getCol() << " at row " << getRow();
}

/*******************************************************************************
 * Function: Generates a random integer that coresponds with a direction
 * Input: None
 * Output: Random Integer from the list 0, 1, 2, 3
 ******************************************************************************/
int human::genMove() {
  return rand() % 4;
}

/*******************************************************************************
 * Function: Checks to see if the generated move goes out of the 8x8 grid bounds
 * Input: None
 * Output: Integer that corresponds w/ direction to move, or 4 if it would be
 *      out of bounds
 ******************************************************************************/
int human::checkMove() { // temp=Move | 4=Can't move
  int temp = genMove();
  if (temp == 0) { // Up
    if (getRow()-1 < 0) {
      return 4;
    }
    else {
      return temp;
    }
  }
  else if (temp == 1) { // Right
    if (getCol()+1 > 7) {
      return 4;
    }
    else {
      return temp;
    }
  }
  else if (temp == 2) { // Down
    if (getRow()+1 > 7) {
      return 4;
    }
    else {
      return temp;
    }
  }
  else {
    if (getCol()-1  < 0) { // Left
      return 4;
    }
    else {
      return temp;
    }
  }
}

/*******************************************************************************
 * Function: Checks if two humans are equal
 * Input: &human
 * Output: true if they are equal, false otherwise
 ******************************************************************************/
bool human::equals(human &otherHuman) {
  if (getType() != otherHuman.getType()) {
    return false;
  }
  else if (getCol() != otherHuman.getCol()) {
    return false;
  }
  else if (getRow() != otherHuman.getRow()) {
    return false;
  }
  else if (getMoved() != otherHuman.getMoved()) {
    return false;
  }
  else {
    return true;
  }
}
