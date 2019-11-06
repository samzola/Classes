#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media { //this is the class for the basic type of media, the parent for all other types
 public: 
  Media();
  char* getTitle(); //keeps track of title and year
  int* getYear();
  virtual int getType(); //type is virtual so it is different for child classes
 private:
  char title[50];
  int year;
};

#endif
