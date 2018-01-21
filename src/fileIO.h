#ifndef fileIO
#define fileIO

    #include <iostream>
    #include <fstream>
    using namespace std;

    /**
      Avlägsnar det första ordet i en sträng, fram till delimitern

      @param &databaseString : strängen som substrängar ska skapas från
      @param delimiter : delimitern som används som avgränsare
    */
    string removeSubstring(string &databaseString, const char delimiter);

    /**
      Gör rotkryptering av char. Ange negativt värde för steps för dekryptering

      @param character : tecknet som ska krypteras
      @param steps : krypteringsnyckel (negativ vid dekryptering)
    */
    unsigned char rot(unsigned char &character, int steps);

    /**
      Skapar en krypterad sträng avdelad med "DELIM" för en persons data

      @param p : personen som ska krypteras
      @param steps : krypteringsnyckel
    */
    string encryptPerson(Person p, int steps);

    /**
      Skapar en person utifrån en krypterad sträng avdelad med "DELIM"

      @param encryptedString : den krypterade strängen
      @param steps : ursprunglig krypteringsnyckel (positiv)
    */
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
