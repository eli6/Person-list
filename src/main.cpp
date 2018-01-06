// main.cpp
// Elin Fritiofsson
// v1.0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "constants.h"
#include "mainFunctions.h"
#include "listFunctions.h"
//----------------------------------------------------------------------------
// Huvudprogram
//----------------------------------------------------------------------------
int main() {

  vector<Person> personer;
  vector<string> menuChoices = {
    "Lägg till en person",
    "Skriv ut listan med personer",
    "Sök efter en person",
    "Ta bort en person",
    "Sortera efter namn",
    "Sortera efter signatur",
    "Sortera efter största längd",
    "Slumpa listan",
    "Avsluta"
  };



  cout << endl;
  cout << "*************************************************"<< endl;
  cout << setw(18) << "" << "PERSONLISTA" << endl;
  cout << "*************************************************" << endl;
  cout << endl;


  //----------------------------------------------------------------------------
  // Utskrift av meny
  //----------------------------------------------------------------------------

  int choice;
  do {
      int numberOfMembers = personer.size();
      cout << endl;
      cout << "Antal personer i listan just nu: " << numberOfMembers << endl;
      choice = printMenu(menuChoices);

      switch(choice)
      {
        case 1: addPersonTo(personer);
          break;
        case 2: printOnScreen(personer);
          break;
        case 3: searchIn(personer);
          break;
        case 4: removeFrom(personer);
          break;
        case 5: sortBy(name, personer);
          break;
        case 6: sortBy(signature, personer);
          break;
        case 7: sortBy(length, personer);
          break;
        case 8: randomize(personer);
          break;
        case 9:
          break;
      }
  } while(choice!=9);


  return 0;
}
