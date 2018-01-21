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

    @param question : kontextberoende fråga som ska
    skrivas ut, t.ex. "Vill du sortera igen?"

    @returns char, antingen "J" eller "N"
    */
    char userWantsToRepeat(string question);

    /**
    Ber användaren ange "m" för att återgå till menyn.
    */
    void returnToMenu();

    /**
    Skriver ut en linje
    */
    void printLine();

    /**
    Skriver ut en linje med stjärnor
    */
    void printStarLine();

    /**
    Kontrollera om input är en int och tilldelar det värdet till variabeln
    Annars ombeds användaren ange talet igen.

    @param &variable : variabeln som ska få ett värde
    */
    void inputAndCheckIfInt(int &variable);

    /**
    Kontrollera om input är en float och tilldelar isåfall det värdet till variabeln
    Annars ombeds användaren ange talet igen.

    @param &variable : variabeln som ska få ett värde
    */
    void inputAndCheckIfFloat(float &variable);

    /**
    Funktion för utskrift av menyn

    @param menuChoice: olika menyval

    @returns int som anger vilket alternativ som valts
    */
    int printMenu(vector<string> menuChoice);


    /**
    Skriver ut rubrikerna i listan
    */
    void printHeadlines();

    /**
    Skriver ut data för en person i listan

    @param p : personen vars data ska skrivas ut
    @param number : personens nummer i ordningsföljden på skärmen (ange 0 om numret inte ska skrivas ut)
    */
    void printPersonData(Person p, int number);

    /**
    Skriver ut personerna i listan på skärmen

    @param personer: referens till listan med personer
    */
    void printOnScreen(vector<Person> personer);

#endif
