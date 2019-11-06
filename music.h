#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media { //make music class a child of media class 
 public:
  Music();
  virtual int getType(); //virtual so it is different from parent and siblings
  char* getArtist(); //keeps track of artist, duration, and publisher
  int* getDuration();
  char* getPublisher();
 private:
  char artist[50];
  int duration;
  char publisher[50];
};

#endif
