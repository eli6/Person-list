#ifndef sortingRandomizing
#define sortingRandomizing

    #include <iostream>
    using namespace std;
    /**
      Slumpar listan

      @param personer: kopia av listan med personer
    */
    void randomize(vector <Person> personer);

    bool signatureSort(const Person &a, const Person &b);

    bool lengthSort(const Person &a, const Person &b);

    bool nameSort(const Person &a, const Person &b);

    /**
      Sorterar listan på olika vis

      @param personer: kopia av listan med personer
      @param type: typ av sortering som ska göras
    */
    void sortBy(SortType type, vector <Person> personer);
#endif
