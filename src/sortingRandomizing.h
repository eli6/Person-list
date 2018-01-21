#ifndef sortingRandomizing
#define sortingRandomizing

    #include <iostream>
    using namespace std;
    /**
      Slumpar listan

      @param personer: kopia av listan med personer
    */
    void randomize(vector <Person> personer);

    /**
      Jämför två personers signaturer

      @param &a : referens till den första personen
      @param &b : referens till den andra personen

      @returns bool om signaturen för &a är mindre än för &b.
    */
    bool signatureSort(const Person &a, const Person &b);

    /**
      Jämför två personers längder

      @param &a : referens till den första personen
      @param &b : referens till den andra personen

      @returns bool om längden på &a är STÖRRE än &b:s längd.
    */
    bool heightSort(const Person &a, const Person &b);

    /**
      Jämför två personers namn

      @param &a : referens till den första personen
      @param &b : referens till den andra personen

      @returns bool om namnet på &a är mindre än &b:s namn.
    */
    bool nameSort(const Person &a, const Person &b);

    /**
      Sorterar listan på olika vis

      @param personer: kopia av listan med personer
      @param type: typ av sortering som ska göras
    */
    void sortBy(SortType type, vector <Person> personer);

#endif
