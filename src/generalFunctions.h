// mainFunctions.h
// Elin Fritiofsson
// v1.0

#ifndef generalFunctions
#define generalFunctions

    #include <iostream>
    #include <string>
    #include <iomanip>
    #include <vector>
    #include "constants.h"
    using namespace std;

    /**
    Funktion som frågar om användaren vill fortsätta med funktionen

    @param question: kontextberoende fråga som ska
    skrivas ut, t.ex. "Vill du sortera igen?"

    @returns char, antingen "J" eller "N"
    */
    char userWantsToRepeat(string question);


    void printLine();

    /**
    Funktion för utskrift av menyn

    @param menuChoice: olika menyval

    @returns int som anger vilket alternativ som valts
    */
    int printMenu(vector<string> menuChoice);



    void printHeadlines();

    void printPersonData(Person p, int number);



    /**
    Skriver ut personerna i listan på skärmen

    @param personer: referens till listan med personer
    */
    void printOnScreen(vector<Person> personer);

#endif
