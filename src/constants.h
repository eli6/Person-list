// constants.h
// Elin Fritiofsson
// v1.0
#ifndef constants
#define constants

  using namespace std;
  #include <string>
  #include <algorithm>

  struct Person {
    string firstName;
    string lastName;
    string signature;
    float length;
  };

  const int maxPersonsShownInList = 2;

  enum SortType {
    name,
    signature,
    length
  };

  const char DELIM = ',';

#endif
