#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {
 public:
  Music();
  virtual int getType();
  char* getArtist();
  int* getDuration();
  char* getPublisher();
 private:
  char artist[50];
  int duration;
  char publisher[50];
};

#endif
