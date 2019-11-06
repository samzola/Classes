#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media { //make movie class a child of media class
 public:
  Movie();
  virtual int getType(); //virtual so it is different from parent and siblings
  char* getDirector(); //keeps track of director, duration, and rating
  int* getDuration();
  float* getRating();
 private:
  char director[50];
  int duration;
  float rating;
};

#endif
