//this is a game, which contains a publisher and rating, along with title and year from parent

#include <iostream>
#include <cstring>
#include "game.h"
#include "media.h"

using namespace std;

Game::Game() {}

char* Game::getPublisher() {
  return publisher;
}

float* Game::getRating() {
  return &rating;
}

int Game::getType() {
  return 1;
}
