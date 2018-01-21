// main.cpp
// Elin Fritiofsson
// v1.0

#include <iostream>
#include <vector>
using namespace std;

#include "constants.h"
#include "generalFunctions.h"
#include "addSearchRemove.h"
#include "sortingRandomizing.h"
#include "fileIO.h"
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
        "Spara listan till en fil",
        "Läs in en lista från en fil",
        "Avsluta"
    };



    cout << endl;
    printStarLine();
    cout << setw(30) << "" << "PERSONLISTA" << endl;
    printStarLine();
    cout << endl;


  //----------------------------------------------------------------------------
  // Utskrift av meny
  //----------------------------------------------------------------------------

    int choice;
    do {
        int numberOfMembers = static_cast<int>(personer.size());
        cout << "ANTAL PERSONER I LISTAN: " << numberOfMembers << endl;
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
        case 7: sortBy(height, personer);
            break;
        case 8: randomize(personer);
            break;
        case 9: saveToFile(personer);
            break;
        case 10: readFromFile(personer);
            break;
        case MAX_MENU_NUMBER:
            break;
        default:
            break;
        }
  } while(choice!=MAX_MENU_NUMBER);


    return 0;
}
