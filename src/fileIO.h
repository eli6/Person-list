#ifndef fileIO
#define fileIO

    #include <iostream>
    #include <fstream>
    using namespace std;

    string removeSubstring(string &databaseString, const char delimiter);

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

      @param personer : kopia av listan med personer
    */
    void saveToFile(vector <Person> personer);

    /**
      Läser in en ny lista till en fil, användaren anger filnamn

      @param personer : referens till listan med personer
    */
    void readFromFile(vector <Person> &personer);
#endif
