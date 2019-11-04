#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media);
void searchY(int year, vector<Media*>* media);
void searchT(char* title, vector<Media*>* media);
void delY(int year, vector<Media*>* media);
void delT(char* title, vector<Media*>* media);

int main() {
  vector<Media*> mediaVect;
  char command[10];
  bool running = true;
  cout << "Welcome to the 'classes' program!" << endl;
  cout << "In this program, you can organize media, such as games, movies, or music." << endl;
  while (running == true) {
    cout << endl << "Please enter a command (add, search, delete, or quit)." << endl;
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
      char yearOrTitle[10];
      int searchYear;
      char searchTitle[50];
      cout << "Would you like to search by year or title?" << endl;
      cin >> yearOrTitle;
      cin.clear();
      cin.ignore(1000000, '\n');
      if (strcmp(yearOrTitle, "year") == 0) {
	cout << "Please enter the year of the media that you want to search for." << endl;
	cin >> searchYear;
	cin.clear();
	cin.ignore(1000000, '\n');
	searchY(searchYear, &mediaVect);
      }
      else if (strcmp(yearOrTitle, "title") == 0) {
	cout << "Please enter the title of the media that you want to search for." << endl;
	cin >> searchTitle;
	cin.clear();
	cin.ignore(1000000, '\n');
	searchT(searchTitle, &mediaVect);
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
    }
    else if (strcmp(command, "delete") == 0) {
      char yearOrTitle[10];
      int delYear;
      char delTitle[50];
      cout << "Would you like to delete by year or title?" << endl;
      cin >> yearOrTitle;
      cin.clear();
      cin.ignore(1000000, '\n');
      if (strcmp(yearOrTitle, "year") == 0) {
	cout << "Please enter the year of the media that you want to delete." << endl;
	cin >> delYear;
	cin.clear();
	cin.ignore(1000000, '\n');
	delY(delYear, &mediaVect);
      }
      else if (strcmp(yearOrTitle, "title") == 0) {
	cout << "Please enter the title of the media that you want to delete." << endl;
	cin >> delTitle;
	cin.clear();
	cin.ignore(1000000, '\n');
	delT(delTitle, &mediaVect);
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
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
    cin.get(game->getTitle(), 50);
    cin.clear();
    cin.ignore(1000000, '\n'); 
    cout << "Year: ";
    cin >> *game->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Publisher: ";
    cin.get(game->getPublisher(), 50);
    cin.clear();
    cin.ignore(1000000, '\n'); 
    cout << "Rating: ";
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media->push_back(game);
  }
  else if (strcmp(addCommand, "music") == 0) {
    Music* music = new Music();
    cout << "Title: ";
    cin.get(music->getTitle(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Year: ";
    cin >> *music->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Artist: ";
    cin.get(music->getArtist(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Publisher: ";
    cin.get(music->getPublisher(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Duration: ";
    cin >> *music->getDuration();
    cin.get();
    media->push_back(music);
  }
  else if (strcmp(addCommand, "movie") == 0) {
    Movie* movie = new Movie();
    cout << "Title: ";
    cin.get(movie->getTitle(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Year: ";
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Director: ";
    cin.get(movie->getDirector(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Duration: ";
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Rating: ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media->push_back(movie);
  }
  else {
    cout << "Invalid command, please try again." << endl;
  }
}

void searchY(int year, vector<Media*>* media) {
  char yesOrNo[5];
  vector<Media*>::iterator i;
  for (i = media->begin(); i != media->end(); ++i) {
    if (year == *(*i)->getYear()) {
      if ((*i)->getType() == 1) { //game
	cout << endl << "Games:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movies:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
    }
  }
}

void searchT(char* title, vector<Media*>* media) {
   char yesOrNo[5];
  vector<Media*>::iterator i;
  for (i = media->begin(); i != media->end(); ++i) {
    if (strcmp(title, (*i)->getTitle()) == 0) {
      if ((*i)->getType() == 1) { //game
	cout << endl << "Games:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movies:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
    }
  } 
}

void delY(int year, vector<Media*>* media) {
  char yesOrNo[5];
  vector<Media*>::iterator i;
  for (i = media->begin(); i != media->end(); ++i) {
    if (year == *(*i)->getYear()) {
      if ((*i)->getType() == 1) { //game
	cout << endl << "Games:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movies:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
      cout << "Are you sure you want to delete? Confirm with 'yes', cancel with 'no'." << endl;
      cin >> yesOrNo;
      cin.get();
      for (int i = 0; i < yesOrNo[i]; i++) {
	if (yesOrNo[i] >= 65 && yesOrNo[i] <= 92) {
	  yesOrNo[i] = yesOrNo[i] + 32;
	}
      }
      if (strcmp(yesOrNo, "yes") == 0) {
	delete *i;
	i = media->erase(i);
	cout << "Deleted!" << endl;
	return;
      }
      else if (strcmp(yesOrNo, "no") == 0) {
	cout << "Deletion canceled." << endl;
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
    }
  }
}

void delT(char* title, vector<Media*>* media) {
   char yesOrNo[5];
  vector<Media*>::iterator i;
  for (i = media->begin(); i != media->end(); ++i) {
    if (strcmp(title, (*i)->getTitle()) == 0) {
      if ((*i)->getType() == 1) { //game
	cout << endl << "Games:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movies:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
      cout << "Are you sure you want to delete? Confirm with 'yes', cancel with 'no'." << endl;
      cin >> yesOrNo;
      cin.get();
      for (int i = 0; i < yesOrNo[i]; i++) {
	if (yesOrNo[i] >= 65 && yesOrNo[i] <= 92) {
	  yesOrNo[i] = yesOrNo[i] + 32;
	}
      }
      if (strcmp(yesOrNo, "yes") == 0) {
	delete *i;
	i = media->erase(i);
	cout << "Deleted!" << endl;
	return;
      }
      else if (strcmp(yesOrNo, "no") == 0) {
	cout << "Deletion canceled." << endl;
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
    }
  } 
}
