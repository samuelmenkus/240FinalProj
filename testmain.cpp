/*******************************************************************************
 * test main file
 * Names: Samuel Menkus, Alden Faville
 *
 * Copyright (C) 2017 by Samuel Menkus, Alden Faville
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "human.h"
#include "zombie.h"
//#include "world.h"

using namespace std;

int main(int argc, char **argv) {

human *sam = new human();
cout << sam->getType() << " " << &sam << endl;
zombie *zombieSam = new zombie(sam);
cout << zombieSam->getType() << " " << &zombieSam << endl;
delete sam;
delete zombieSam;

zombie *alden = new zombie();
cout << alden->getType() << " " << &alden << endl;
delete alden;







  return 0;
}
