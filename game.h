#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game : public Media { //game class is child of media class
 public:
  Game();
  char* getPublisher(); //keeps track of publisher and rating
  float* getRating();
  virtual int getType(); //virtual so it is different from its parent and siblings
 private:
  char publisher[50];
  float rating;
};

#endif
