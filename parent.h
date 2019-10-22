#include <iostream>
#include <string.h>

using namespace std;

class Parent {
 public:
  Media(string*);
  string* getDescription();
 private:
  string* description;
};
