// functions.cpp
// Elin Fritiofsson
// v1.0

#include "mainFunctions.h"

void printLine(){
  cout << "------------------------------------------------------------------------" << endl;
}

int printMenu(vector<string> menuChoices){

  int choice;

  cout << endl;
  printLine();
  cout <<  "Menyval:" << endl;
  printLine();
  cout << endl;

  for(size_t i = 0; i < menuChoices.size(); i++){

    cout << i+1 << ". " << menuChoices[i] << endl;

  }
  printLine();

  cin >> choice;
  cin.get();

  return choice;
}
