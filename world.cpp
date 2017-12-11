/*******************************************************************************
 * world class header file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
 #include <iostream>
 #include <cstdlib>
 #include "world.h"

 using namespace std;

 //constructors/deconstructor
   world::world() {

   }

   world::~world() {

   }

 //getters/setters
   int world::getDay() {
     return day;
   }

 //methods
   void world::turnHuman(human& oldHuman) {
     zombie(oldHuman);
   }
   void world::move() {

   }

   void world::progressDay() {
     //TODO: Add way for zombies and humans to move in this method
     day++;
   }

   void world::printGrid()
   {
     cout << "World at Day " << getDay() << endl;
     cout << "+---+---+---+---+---+---+---+---+" << endl;
  	 for(int i = 0; i < 8; i++) {
  		cout << "| ";
  		for(int j = 0; j < 8; j++) {
  			cout << grid[i][j] << " | ";
  		}
  		cout << endl;
  		cout << "+---+---+---+---+---+---+---+---+" << endl;
  	}
  }
