#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void add();
//void search(vector<Room*> &list);
//void del(vector<Room*> &list);
	 
int main() {
  bool running = true;
  // vector<Room*> list;
  char command[8];
  char cAdd[8] = "add";
  char cSearch[8] = "search";
  char cDel[8] = "delete";
  char cQuit[8] = "quit";
  while (running = true) {
    cout << "Please enter a valid command (add, search, delete, or quit);" << endl;
    cin >> command;
    cin.get();
    for (int i = 0; i < command[i]; i++) {
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(cAdd, command) == 0) {
      add();
      cout << "ADD" << endl;
    }
    else if (strcmp(cSearch, command) == 0) {
      // search(list);
    }
    else if (strcmp(cDel, command) == 0) {
      //  del(list);
    }
    else if (strcmp(cQuit, command) == 0) {
      running = false;
    }
    else {
      cout << "Invalid command." << endl;
    }
  }
  return 0;
}

void add() {
  char addTypeI[15];
  char cVG[11] = "videogame";
  char cMusic[8] = "music";
  char cMovie[8] = "movie";
  cout << "Enter the name of the media you would like to add (videogame, music, movie)" << endl;
  cin >> addTypeI;
  cin.get();
  for (int i = 0; i < addTypeI[i]; i++) {
    if (addTypeI[i] >= 65 && addTypeI[i] <= 92) {
      addTypeI[i] = addTypeI[i] + 32;
    }
  }
  if (strcmp(cVG, addTypeI) == 0) {
    cout << "VG" << endl;
    //add video game 
  }
  else if (strcmp(cMusic, addTypeI) == 0) {
    //add music
  }
  else if (strcmp(cMovie, addTypeI) == 0) {
    //add movie
  }
  else {
    cout << "Invalid command." << endl;
  }
  }
