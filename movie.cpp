#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie() {}

int Movie::getType() {
  return 2;
}

char* Movie::getDirector() {
  return director;
}

float* Movie::getRating() {
  return &rating;
}

int* Movie::getDuration() {
  return &duration;
}
