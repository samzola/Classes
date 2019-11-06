/*
 * Author: Sam Zola
 * Date: 11/06/2019
 * Program: This program allows the user to organize media (games, music, and movies). The user *  can add, search, and delete media from the program.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media); //function for adding media
void searchY(int year, vector<Media*>* media); //function for searching by year
void searchT(char* title, vector<Media*>* media); //function for searching by title
void delY(int year, vector<Media*>* media); //function for deleting by year
void delT(char* title, vector<Media*>* media); //function for deleting by title

int main() {
  vector<Media*> mediaVect; //create vector that keeps all media inside it
  char command[10]; //this is the command input
  bool running = true; //keeps track of if the game is running
  //tell the user what the program is and how to start playing
  cout << "Welcome to the 'classes' program!" << endl;
  cout << "In this program, you can organize media, such as games, movies, or music." << endl;
  while (running == true) {
    cout << endl << "Please enter a command (add, search, delete, or quit)." << endl;
    cin >> command; //read in command
    cin.get();
    //make it lowercase
    for (int i = 0; i < command[i]; i++) {
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(command, "add") == 0) { //if the user enters "add," run add function
      add(&mediaVect);
    }
    //if the user enters "search," ask if they want to search by year or title
    else if (strcmp(command, "search") == 0) {
      char yearOrTitle[10];
      int searchYear;
      char searchTitle[50];
      cout << "Would you like to search by year or title?" << endl;
      cin >> yearOrTitle; //read in choice
      cin.clear();
      cin.ignore(1000000, '\n');
      if (strcmp(yearOrTitle, "year") == 0) { //if user enters "year," ask for the year
	cout << "Please enter the year of the media that you want to search for." << endl;
	cin >> searchYear; //read in year
	cin.clear();
	cin.ignore(1000000, '\n');
	searchY(searchYear, &mediaVect); //run search by year function using inputted year
      }
      else if (strcmp(yearOrTitle, "title") == 0) { //if the user enters "title," ask for title
	cout << "Please enter the title of the media that you want to search for." << endl;
	cin >> searchTitle; //read in title
	cin.clear();
	cin.ignore(1000000, '\n');
	searchT(searchTitle, &mediaVect); //run search by title function using inputted title
      }
      else { //if neither year or title entered, tell user
	cout << "Invalid command, please try again." << endl;
      }
    }
    //if the user enters "delete," ask if they want to delete by year or title
    else if (strcmp(command, "delete") == 0) {
      char yearOrTitle[10];
      int delYear;
      char delTitle[50];
      cout << "Would you like to delete by year or title?" << endl;
      cin >> yearOrTitle; //read in choice
      cin.clear();
      cin.ignore(1000000, '\n');
      if (strcmp(yearOrTitle, "year") == 0) { //if the user enters "year," ask for the year
	cout << "Please enter the year of the media that you want to delete." << endl;
	cin >> delYear; //read in year
	cin.clear();
	cin.ignore(1000000, '\n');
	delY(delYear, &mediaVect); //run delete by year function using inputted year
      }
      else if (strcmp(yearOrTitle, "title") == 0) { //if the user enters "title, ask for title
	cout << "Please enter the title of the media that you want to delete." << endl;
	cin >> delTitle; //read in title
	cin.clear();
	cin.ignore(1000000, '\n');
	delT(delTitle, &mediaVect); //run delete by title function using inputted title 
      }
      else { //if neither year or title entered, tell user
	cout << "Invalid command, please try again." << endl;
      }
    }
    else if (strcmp(command, "quit") == 0) { //if user enters "quit," end program
      running = false;
    }
    else { //if user doesn't enter a correct command, tell them
      cout << "Invalid command, please try again." << endl;
    }
  }
  return 0;
}

void add(vector<Media*>* media) { //function for adding media
  char addCommand[10];
  //ask which type of media the user wants to add
  cout << "What type of media would you like to add (game, movie, music)?" << endl;
  cin >> addCommand; //read in choice
  cin.get();
  for (int i = 0; i < addCommand[i]; i++) { //make input lowercase
    if (addCommand[i] >= 65 && addCommand[i] <= 92) {
      addCommand[i] = addCommand[i] + 32;
    }
  }
  //if user enters "game," have user input all necessary data for a game
  if (strcmp(addCommand, "game") == 0) {
    Game* game = new Game(); //make a new game
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
    cout << "Rating (out of 10): ";
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media->push_back(game); //add game to media database
  }
  //if user enters "music," have user input all necessary data for music
  else if (strcmp(addCommand, "music") == 0) {
    Music* music = new Music(); //make new music
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
    cout << "Duration (in seconds): ";
    cin >> *music->getDuration();
    cin.get();
    media->push_back(music); //add music to media database
  }
  //if user enters "movie," have user input all necessary data for a movie
  else if (strcmp(addCommand, "movie") == 0) {
    Movie* movie = new Movie(); //make a new movie
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
    cout << "Duration (in minutes): ";
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Rating (out of 10): ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media->push_back(movie); //add movie to media database
  }
  else { //if user doesn't enter a valid media type, tell them
    cout << "Invalid command, please try again." << endl;
  }
}

void searchY(int year, vector<Media*>* media) { //function for searching by year
  char yesOrNo[5];
  vector<Media*>::iterator i; //create iterator for the vector
  for (i = media->begin(); i != media->end(); ++i) { //run through vector
    //if inputted year matches any years in the database, display the corresponding media
    if (year == *(*i)->getYear()) {
      if ((*i)->getType() == 1) { //show all matching games
	cout << endl << "Game:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 2) { //show all matching movies
	cout << endl << "Movie:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << " minutes" << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 3) { //show all matching music
	cout << endl << "Music:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << " seconds" << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
      else { //if the inputted year doesn't match, tell user
	cout << "No match found. Please try again." << endl;
      }
    }
  }
}

void searchT(char* title, vector<Media*>* media) { //function for searching by title
   char yesOrNo[5];
   vector<Media*>::iterator i; //create iterator for the vector
   for (i = media->begin(); i != media->end(); ++i) { //run through vector
    //if inputted title matches any titles in the database, display the corresponding media 
    if (strcmp(title, (*i)->getTitle()) == 0) {
      if ((*i)->getType() == 1) { //show all matching games
	cout << endl << "Game:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movie:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << " minutes" << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << " seconds" << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
      else { //if the inputted title doesn't match, tell user.
	cout << "No match found. Please try again." << endl;
      }
    }
  } 
}

void delY(int year, vector<Media*>* media) { //function for deleting by year
  //NOTE: this code is the exact same as searching by year, up until the deletion, which I will comment.
  char yesOrNo[5];
  vector<Media*>::iterator i;
  for (i = media->begin(); i != media->end(); ++i) {
    if (year == *(*i)->getYear()) {
      if ((*i)->getType() == 1) { //game
	cout << endl << "Games" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 2) { //movie
	cout << endl << "Movies:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << " minutes" << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << "/10" << endl;
      }
      else if ((*i)->getType() == 3) { //music
	cout << endl << "Music:" << endl;
	cout << "Title: " << (*i)->getTitle() << endl;
	cout << "Year: " << *(*i)->getYear() << endl;
	cout << "Artist: " << dynamic_cast<Music*>(*i)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*i)->getDuration() << " seconds" << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*i)->getPublisher() << endl;
      }
      else {
	cout << "No matching year found. Please try again." << endl;
      }
      //confirm if the user wants to delete
      cout << "Are you sure you want to delete? Confirm with 'yes', cancel with 'no'." << endl;
      cin >> yesOrNo;
      cin.get();
      for (int i = 0; i < yesOrNo[i]; i++) {
	if (yesOrNo[i] >= 65 && yesOrNo[i] <= 92) {
	  yesOrNo[i] = yesOrNo[i] + 32;
	}
      }
      if (strcmp(yesOrNo, "yes") == 0) { //if yes, delete the media from the vector
	delete *i;
	i = media->erase(i);
	cout << "Deleted!" << endl; //tell user
	return;
      }
      else if (strcmp(yesOrNo, "no") == 0) { //if no, cancel deletion
	cout << "Deletion canceled." << endl;
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
    }
  }
}

void delT(char* title, vector<Media*>* media) { //function for deleting by title
  //NOTE: this code is the exact same as searching by title, up until the deletion, which I will comment.
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
	cout << "Duration: " << *dynamic_cast<Movie*>(*i)->getDuration() << " minutes" << endl;
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
      else {
	cout << "No matching title found. Please try again." << endl;
      }
      //confirm if the user wants to delete
      cout << "Are you sure you want to delete? Confirm with 'yes', cancel with 'no'." << endl;
      cin >> yesOrNo;
      cin.get();
      for (int i = 0; i < yesOrNo[i]; i++) {
	if (yesOrNo[i] >= 65 && yesOrNo[i] <= 92) {
	  yesOrNo[i] = yesOrNo[i] + 32;
	}
      }
      if (strcmp(yesOrNo, "yes") == 0) { //if yes, then delete media from vector
	delete *i;
	i = media->erase(i);
	cout << "Deleted!" << endl; //tell user
	return;
      }
      else if (strcmp(yesOrNo, "no") == 0) { //if no, cancel deletion
	cout << "Deletion canceled." << endl;
      }
      else {
	cout << "Invalid command, please try again." << endl;
      }
    }
  } 
}
