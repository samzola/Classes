#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media);

int main() {
  vector<Media*> mediaVect;
  char command[10];
  bool running = true;
  cout << "Welcome to the 'classes' program!." << endl;
  cout << "In this program, you can organize media such as games, movies, or music." << endl;
  while (running == true) {
    cout << "To get started, enter a command (add, search, delete, or quit)." << endl;
    cin >> command;
    cin.get();
    for (int i = 0; i < command[i]; i++) {
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(command, "add") == 0) {
      //add(mediaVect);
      cout << "ADD" << endl;
    }
    else if (strcmp(command, "search") == 0) {
      //search(mediaVect);
      cout << "SEARCH" << endl;
    }
    else if (strcmp(command, "delete") == 0) {
      //del(mediaVect);
      cout << "DELETE" << endl;
    }
    else if (strcmp(command, "quit") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid command (add, search, delete, quit)" << endl;
    }
  }
  return 0;
}
