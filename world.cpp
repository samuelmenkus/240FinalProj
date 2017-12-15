/*******************************************************************************
 * Name: Samuel Menkus & Alden Faville
 * Email: smenkus@email.sc.edu & afaville@email.sc.edu
 * Function: Implements world.h
 * Input: None
 * Output: Varies
 * Completed: 12-15-2017
 * Comments:
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include "world.h"

using namespace std;

//constructors/deconstructor
/*******************************************************************************
 * Function: Default Constructor
 * Input: None
 * Output: None
 ******************************************************************************/
world::world() {
  day = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = ' ';
    }
  }

  intNumHumans = (rand() % 62) + 1;
  intNumZombies = (rand() % (64 - intNumHumans)) + 1;

  for (int i = 0; i < intNumHumans; i++) { // Populates human vector
    humans.push_back(human());
  }

  for (int i = 0; i < intNumZombies; i++) { // Populates zombie vector
    zombies.push_back(zombie());
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

/*******************************************************************************
 * Function: De-Constructor
 * Input: None
 * Output: None
 ******************************************************************************/
world::~world() {

}

//getters/setters
/*******************************************************************************
 * Function: Returns the current day of the world
 * Input: None
 * Output: int representing day
 ******************************************************************************/
int world::getDay() {
  return day;
}

//methods
/*******************************************************************************
 * Function: Changes a human to a zombie, and adds a new zombie to the "zombies"
        vector, while removing the human from the "humans" vector
 * Input: &human
 * Output: None
 ******************************************************************************/
void world::turnHuman(human &oldHuman) {
  zombies.push_back(zombie());
  zombies.back().setCol(oldHuman.getCol());
  zombies.back().setRow(oldHuman.getRow());
  zombies.back().setMoved(oldHuman.getMoved());

  for (int i = 0; i < humans.size(); i++) {
    if (humans.at(i).equals(oldHuman)) {
      grid[humans.at(i).getCol()][humans.at(i).getRow()] = 'Z';
      humans.erase(humans.begin()+i);
    }
  }
}

/*******************************************************************************
 * Function: Creates and executes a move for a human
 * Input: Human
 * Output: None
 ******************************************************************************/
void world::moveH(human &current) {
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
      grid[current.getCol()][current.getRow()] = ' ';
      current.setRow(current.getRow()-1);
      grid[current.getCol()][current.getRow()] = current.getType();
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
      grid[current.getCol()][current.getRow()] = ' ';
      current.setCol(current.getCol()+1);
      grid[current.getCol()][current.getRow()] = current.getType();
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
      grid[current.getCol()][current.getRow()] = ' ';
      current.setRow(current.getRow()+1);
      grid[current.getCol()][current.getRow()] = current.getType();
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
      grid[current.getCol()][current.getRow()] = ' ';
      current.setCol(current.getCol()-1);
      grid[current.getCol()][current.getRow()] = current.getType();
      current.setMoved(true);
    }
  }
}

/*******************************************************************************
 * Function: Creates and executes a move for a zombie
 * Input: Human
 * Output: None
 ******************************************************************************/
void world::moveZ(zombie &current) {
  int temp = current.checkMove();
  if (temp == 4) { // can't move because bounds
    current.setMoved(true);
  }
  else if (temp == 0) { // up
    if (grid[current.getCol()][current.getRow()-1] == 'H') {
      current.setMoved(true);
      for (int i = 0; i < humans.size(); i++) {
        if (humans.at(i).getCol() == current.getCol() && humans.at(i).getRow() == current.getRow()-1) {
          turnHuman(humans.at(i));
        }
      }
    }
    else if (grid[current.getCol()][current.getRow()-1] == 'Z') {
      current.setMoved(true);
    }
    else {
      grid[current.getCol()][current.getRow()] = ' ';
      current.setRow(current.getRow()-1);
      grid[current.getCol()][current.getRow()] = current.getType();
      current.setMoved(true);for (int i = 0; i < humans.size(); i++) {
        if (humans.at(i).getCol() == current.getCol() && humans.at(i).getRow() == current.getRow()-1) {
          turnHuman(humans.at(i));
        }
      }
    }
  }
  else if (temp == 1) { // right
    if (grid[current.getCol()+1][current.getRow()] == 'H') {
      current.setMoved(true);
      for (int i = 0; i < humans.size(); i++) {
        if (humans.at(i).getCol() == current.getCol()+1 && humans.at(i).getRow() == current.getRow()) {
          turnHuman(humans.at(i));
        }
      }
    }
    else if (grid[current.getCol()+1][current.getRow()] == 'Z') {
      current.setMoved(true);
    }
    else {
      grid[current.getCol()][current.getRow()] = ' ';
      current.setCol(current.getCol()+1);
      grid[current.getCol()][current.getRow()] = current.getType();
      current.setMoved(true);
    }
  }
  else if (temp == 2) { // down
    if (grid[current.getCol()][current.getRow()+1] == 'H') {
      current.setMoved(true);
      for (int i = 0; i < humans.size(); i++) {
        if (humans.at(i).getCol() == current.getCol() && humans.at(i).getRow() == current.getRow()+1) {
          turnHuman(humans.at(i));
        }
      }
    }
    else if (grid[current.getCol()][current.getRow()+1] == 'Z') {
      current.setMoved(true);
    }
    else {
      grid[current.getCol()][current.getRow()] = ' ';
      current.setRow(current.getRow()+1);
      grid[current.getCol()][current.getRow()] = current.getType();
      current.setMoved(true);
    }
  }
  else { // left
    if (grid[current.getCol()-1][current.getRow()] == 'H') {
      current.setMoved(true);
      for (int i = 0; i < humans.size(); i++) {
        if (humans.at(i).getCol() == current.getCol()-1 && humans.at(i).getRow() == current.getRow()) {
          turnHuman(humans.at(i));
        }
      }
    }
    else if (grid[current.getCol()-1][current.getRow()] == 'Z') {
      current.setMoved(true);
    }
    else {
      grid[current.getCol()][current.getRow()] = ' ';
      current.setCol(current.getCol()-1);
      grid[current.getCol()][current.getRow()] = current.getType();
      current.setMoved(true);
    }
  }
}

/*******************************************************************************
 * Function: Progesses the current day of the world
 * Input: None
 * Output: None
 ******************************************************************************/
void world::progressDay() {
  for (int i = 0; i < humans.size(); i++) {
    humans.at(i).setMoved(false);
  }

  for (int i = 0; i < zombies.size(); i++) {
    zombies.at(i).setMoved(false);
  }

  for (int i = 0; i < humans.size(); i++) {
    if (!humans.at(i).getMoved()) {
      moveH(humans.at(i));
    }
  }

  for (int i = 0; i < zombies.size(); i++) {
    if (!zombies.at(i).getMoved()) {
      moveZ(zombies.at(i));
    }
  }

/*
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
*/

  day++;
  printGrid();
}

/*******************************************************************************
 * Function: Returns a bool showing whether or not the vector of humans is empty
 * Input: None
 * Output: returns a bool representing if the humans vector is empty or not
 ******************************************************************************/
bool world::humansDed() {
  return humans.empty();
}

/*******************************************************************************
 * Function: Prints the grid (world)
 * Input: None
 * Output: Prints current world
 ******************************************************************************/
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
