// diceRoll.h
// Elin Fritiofsson
// v1.0

#ifndef listFunctions
#define listFunctions

    #include <iostream>
    #include <vector>
    #include <string>
    #include <iomanip>
    #include <algorithm>
    #include <fstream>
    #include "constants.h"

    using namespace std;


    /**
      Funktion som frågar om användaren vill fortsätta med funktionen

      @param question: kontextberoende fråga som ska
      skrivas ut, t.ex. "Vill du sortera igen?"

      @returns char, antingen "J" eller "N"
    */
    char userWantsToRepeat(string question);

    /**
      Kontrollerar om två personer är identiska

      @param p1: första personen
      @param p2: andra personen
    */
    bool areIdentical(Person p1, Person p2);


    bool signatureSort(const Person &a, const Person &b);

    bool lengthSort(const Person &a, const Person &b);

    bool nameSort(const Person &a, const Person &b)

    bool areIdentical(Person p1, Person p2)

    void printHeadlines()

    void printPersonData(Person p, int number)

    /**
      Lägger till en person i listan med personer

      @param personer: referens till listan med personer
    */
    void addPersonTo(vector <Person> &personer);

    /**
      Skriver ut personerna i listan på skärmen

      @param personer: referens till listan med personer
    */
    void printOnScreen(vector<Person> personer);

    /**
      Söker efter en person med en signatur som användaren anger.

      @param personer: listan med persone
      @returns int för personens index i vektorn. Hittas ingen person
      returneras värdet -1
    */
    vector<Person>::const_iterator findIndexWithSignatureIn(vector <Person> &personer);

    /**
      Söker efter den person i listan vars signatur användaren anger
      och skriver ut resultatet

      @param personer: kopia av listan med personen
    */
    void searchIn(vector <Person> personer);

    /**
      Tar bort personen som har den signatur som användaren anger

      @param personer: referens till listan med personer
    */
    void removeFrom(vector <Person> &personer);

    /**
      Sorterar listan på olika vis

      @param personer: kopia av listan med personer
      @param type: typ av sortering som ska göras
    */
    void sortBy(SortType type, vector <Person> personer);

    /**
      Slumpar listan

      @param personer: kopia av listan med personer
    */
    void randomize(vector <Person> personer);

    string removeSubstring(string &databaseString, const char delimiter)

    /**
      Gör rotkryptering av char. Ange negativt värde för steps för dekryptering

      @param character : tecknet som ska krypteras
      @param steps : krypteringsnyckel (negativ vid dekryptering)
    */
    unsigned char rot(unsigned char &character, int steps);

    string encryptPerson(Person p, int steps);

    Person decryptPerson(string encryptedString, int steps);

    /**
      Sparar listan till en fil, användaren anger filnamn

      @param personer: kopia av listan med personer
    */
    void saveToFile(vector <Person> personer);

    /**
      Läser in en ny lista till en fil, användaren anger filnamn

      @param personer: referens till listan med personer
    */
    void readFromFile(vector <Person> &personer);

    #endif
