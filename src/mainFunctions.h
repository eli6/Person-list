// mainFunctions.h
// Elin Fritiofsson
// v1.0

#ifndef mainFunctions
#define mainFunctions

  #include <iostream>
  #include <string>
  #include <iomanip>
  #include <vector>

  using namespace std;


  void printLine();
  /**
      Funktion för utskrift av menyn

      @param menuChoice: olika menyval

      @returns int som anger vilket alternativ som valts
  */
  int printMenu(vector<string> menuChoice);

#endif
