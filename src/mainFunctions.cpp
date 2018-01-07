// functions.cpp
// Elin Fritiofsson
// v1.0

#include "mainFunctions.h"
#include "constants.h"

void printLine(){
  cout << "------------------------------------------------------------------------" << endl;
}

void checkIfNumber(int &variable){
  bool correctInput = false;
  do {
    cin >> variable;
    cin.get();

    if(!cin) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Ange ett tal" << endl;
      correctInput = false;
    } else {
      correctInput = true;
    }
  } while(correctInput != true);
}

int printMenu(vector<string> menuChoices){

  int choice = 0;

  cout << endl;
  printLine();
  cout <<  "Menyval:" << endl;
  printLine();
  cout << endl;

  for(size_t i = 0; i < menuChoices.size(); i++){

    cout << i+1 << ". " << menuChoices[i] << endl;

  }
  printLine();

  do {
    checkIfNumber(choice);
    if(choice > MAX_MENU_NUMBER){
      cout << "Ange ett tal mellan 1 och " << MAX_MENU_NUMBER << endl;
    }
  } while(choice > MAX_MENU_NUMBER);

  return choice;
}
