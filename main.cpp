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
    cout << "Please enter a command (add, search, delete, or quit)." << endl;
    cin >> command;
    cin.get();
    for (int i = 0; i < command[i]; i++) {
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(command, "add") == 0) {
      add(&mediaVect);
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
      cout << "Invalid command, please try again." << endl;
    }
  }
  return 0;
}

void add(vector<Media*>* media) {
  char addCommand[10];
  cout << "What type of media would you like to add (game, movie, music)?" << endl;
  cin >> addCommand;
  cin.get();
  for (int i = 0; i < addCommand[i]; i++) {
    if (addCommand[i] >= 65 && addCommand[i] <= 92) {
      addCommand[i] = addCommand[i] + 32;
    }
  }
  if (strcmp(addCommand, "game") == 0) {
    Game* game = new Game();
    cout << "Title: ";
    cin >> game->getTitle();
    cin.get();
    cout << "Year: ";
    cin >> *game->getYear();
    cin.get();
    cout << "Publisher: ";
    cin >> game->getPublisher();
    cin.get();
    cout << "Rating: ";
    cin >> *game->getRating();
    cin.get();
    media->push_back(game);
  }
  else if (strcmp(addCommand, "music") == 0) {
    Music* music = new Music();
    cout << "Title: ";
    cin >> music->getTitle();
    cin.get();
    cout << "Year: ";
    cin >> *music->getYear();
    cin.get();
    cout << "Artist: ";
    cin >> music->getArtist();
    cin.get();
    cout << "Publisher: ";
    cin >> music->getPublisher();
    cin.get();
    cout << "Duration: ";
    cin >> *music->getDuration();
    cin.get();
    media->push_back(music);
  }
  else if (strcmp(addCommand, "movie") == 0) {
    Movie* movie = new Movie();
    cout << "Title: ";
    cin >> movie->getTitle();
    cin.get();
    cout << "Year: ";
    cin >> *movie->getYear();
    cin.get();
    cout << "Director: ";
    cin >> movie->getDirector();
    cin.get();
    cout << "Duration: ";
    cin >> *movie->getDuration();
    cin.get();
    cout << "Rating: ";
    cin >> *movie->getRating();
    cin.get();
    media->push_back(movie);
  }
  else {
    cout << "Invalid command, please try again." << endl;
  }
}
