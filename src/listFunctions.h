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
      Konverterar en persons för- och efternamn till gemener

      @param p: referens till en Person
  */
  void convertToLower(Person &p);

  /**
      Kontrollerar om två personer är identiska

      @param p1: första personen
      @param p2: andra personen
  */
  bool areIdentical(Person p1, Person p2);

  /**
      Skapar en unik signatur för en person i en vektor

      @param person: personen som ska få en signatur
      @param personer: vectorn med personer som signaturen måste vara unik i
  */
  void addSignature(Person &person, vector<Person> personer);


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
  int findIndexWithSignatureIn(vector <Person> personer);

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

#endif
