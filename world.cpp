/*******************************************************************************
 * world class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include "world.h"

using namespace std;

//constructors/deconstructor
world::world() {
  int day = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = ' ';
    }
  }

  intNumHumans = (rand() % 62) + 1;
  intNumZombies = (rand() % (64 - intNumHumans)) + 1;

  for (int i = 0; i < intNumHumans; i++) { // Populates human vector
    humans.at(i) = human();
  }

  for (int i = 0; i < intNumZombies; i++) { // Populates zombie vector
    zombies.at(i) = zombie();
  }

  for (int i = 0; i < intNumHumans; i++) { // Sets positions of humans
    bool taken = true;
    int tempCol, tempRow;
    while (taken) {
      taken = false;
      tempRow = rand() % 8;
      tempCol = rand() % 8;

      if (grid[tempCol][tempRow] == 'H') {
        taken = true;
      }
      else {
        humans.at(i).setCol(tempCol);
        humans.at(i).setRow(tempRow);
        grid[tempCol][tempRow] = 'H';
      }
    }
  }

  for (int i = 0; i < intNumZombies; i++) { // Sets positions of zombies
    bool taken = true;
    int tempCol, tempRow;
    while (taken) {
      taken = false;
      tempRow = rand() % 8;
      tempCol = rand() % 8;

      if (grid[tempCol][tempRow] == 'H' || grid[tempCol][tempRow] == 'Z') {
        taken = true;
      }
      else {
        zombies.at(i).setCol(tempCol);
        zombies.at(i).setRow(tempRow);
        grid[tempCol][tempRow] = 'Z';
      }
    }
  }
}

world::~world() {

}

//getters/setters
int world::getDay() {
  return day;
}

 //methods
void world::turnHuman(human &oldHuman) {
  zombies.push_back(zombie());
  zombies.back().setCol(oldHuman.getCol());
  zombies.back().setRow(oldHuman.getRow());
  zombies.back().setMoved(oldHuman.getMoved());

  for (int i = 0; i < humans.size(); i++) {
    if (humans.at(i).equals(oldHuman)) {
      humans.erase(humans.begin()+i);
    }
  }
}

void world::move(human &current) {
  int temp = current.checkMove();
  if (temp == 4) { // can't move because bounds
    current.setMoved(true);
  }
  else if (temp == 0) { // up
    if (grid[current.getCol()][current.getRow()-1] == 'H') {
      current.setMoved(true);
    }
    else if (grid[current.getCol()][current.getRow()-1] == 'Z') {
      current.setMoved(true);
      turnHuman(current);
    }
    else {
      current.setRow(current.getRow()-1);
      current.setMoved(true);
    }
  }
  else if (temp == 1) { // right
    if (grid[current.getCol()+1][current.getRow()] == 'H') {
      current.setMoved(true);
    }
    else if (grid[current.getCol()+1][current.getRow()] == 'Z') {
      current.setMoved(true);
      turnHuman(current);
    }
    else {
      current.setCol(current.getCol()+1);
      current.setMoved(true);
    }
  }
  else if (temp == 2) { // down
    if (grid[current.getCol()][current.getRow()+1] == 'H') {
      current.setMoved(true);
    }
    else if (grid[current.getCol()][current.getRow()+1] == 'Z') {
      current.setMoved(true);
      turnHuman(current);
    }
    else {
      current.setRow(current.getRow()+1);
      current.setMoved(true);
    }
  }
  else { // left
    if (grid[current.getCol()-1][current.getRow()] == 'H') {
      current.setMoved(true);
    }
    else if (grid[current.getCol()-1][current.getRow()-1] == 'Z') {
      current.setMoved(true);
      turnHuman(current);
    }
    else {
      current.setCol(current.getCol()-1);
      current.setMoved(true);
    }
  }
}

void world::progressDay() {
  for (int i = 0; i < humans.size(); i++) {
    humans.at(i).setMoved(false);
  }

  for (int i = 0; i < zombies.size(); i++) {
    zombies.at(i).setMoved(false);
  }

  for (int i = 0; i < humans.size(); i++) {
    if (humans.at(i).getMoved()) {
      move(humans.at(i));
    }
  }

  for (int i = 0; i < zombies.size(); i++) {
    if (!zombies.at(i).getMoved()) {
      move(zombies.at(i));
    }
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = ' ';
    }
  }

  for (int i = 0; i < humans.size(); i++) {
    grid[humans.at(i).getCol()][humans.at(i).getRow()] = 'H';
  }

  for (int i = 0; i < zombies.size(); i++) {
    grid[zombies.at(i).getCol()][zombies.at(i).getRow()] = 'Z';
  }

  day++;
  printGrid();
}

bool world::humansDed() {
  return humans.empty();
}

void world::printGrid() {
  cout << "World at Day " << getDay() << endl;
  cout << "+---+---+---+---+---+---+---+---+" << endl;
  for (int i = 0; i < 8; i++) {
    cout << "| ";
    for (int j = 0; j < 8; j++) {
      cout << grid[i][j] << " | ";
    }
    cout << endl;
    cout << "+---+---+---+---+---+---+---+---+" << endl;
  }
}
