#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game : public Media {
 public:
  Game();
  char* getPublisher();
  float* getRating();
  virtual int getType();
 private:
  char publisher[50];
  float rating;
};

#endif
