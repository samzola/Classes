#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media() {}

char* Media::getTitle() {
  return title;
}

int* Media::getYear() {
  return &year;
}

int Media::getType() {
  return 0;
}
