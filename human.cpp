/*******************************************************************************
 * human class file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "human.h"

using namespace std;

//constructors/deconstructor
human::human() {
  type = 'H';
}

human::human(human &oldHuman) {
  type = oldHuman.getType();
}

human::~human() {

}

char human::getType() {
  return type;
}

int human::getRow() {
  return row;
}

int human::getCol() {
  return col;
}

bool human::getMoved() {
  return moved;
}

void human::setRow(int _row) {
  if (_row >= 0 && _row < 8) {
    row = _row;
  }
}

void human::setCol(int _col) {
  if (_col >= 0 && _col < 8) {
    col = _col;
  }
}

void human::setMoved(bool _moved) {
  moved = _moved;
}

void human::print() {
  cout << getType();
}

int human::genMove() {
  return rand() % 4;
}

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
