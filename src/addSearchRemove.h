#ifndef addSearchRemove
#define addSearchRemove

    #include <iostream>
    using namespace std;

    /**
      Kontrollerar om två personer är identiska

      @param p1 : första personen
      @param p2 : andra personen
    */
    bool areIdentical(Person p1, Person p2);


    /**
      Lägger till en person i listan med personer

      @param personer : referens till listan med personer
    */
    void addPersonTo(vector <Person> &personer);

    /**
      Söker efter en person med en signatur som användaren anger.

      @param personer : listan med persone
      @returns int för personens index i vektorn. Hittas ingen person
      returneras värdet -1
    */
    vector<Person>::const_iterator findIndexWithSignatureIn(vector <Person> &personer);

    /**
      Söker efter den person i listan vars signatur användaren anger
      och skriver ut resultatet

      @param personer : kopia av listan med personen
    */
    void searchIn(vector <Person> personer);

    /**
      Tar bort personen som har den signatur som användaren anger

      @param personer : referens till listan med personer
    */
    void removeFrom(vector <Person> &personer);
#endif
